#include <stdio.h>
#include <time.h>

#define IS_SET(NUM, N) (NUM & (1 << N))
#define ON "\033[31m⬤\033[0m"
#define OFF "⬤"
#define C(NUM, N) (IS_SET(NUM, N) ? ON : OFF)

const char *clock_fmt =
    "  %s    %s    %s\n"
    "  %s  %s %s  %s %s\n"
    "%s %s  %s %s  %s %s\n"
    "%s %s  %s %s  %s %s\n";

int main() {
    time_t now = time(0);
    struct tm *local = localtime(&now);
    
    short h[] = {local->tm_hour % 10, local->tm_hour / 10};
    short m[] = {local->tm_min % 10, local->tm_min / 10};
    short s[] = {local->tm_sec % 10, local->tm_sec / 10};

    printf(
        clock_fmt,
        C(h[0], 3), C(m[0], 3), C(s[0], 3),
        C(h[0], 2), C(m[1], 2), C(m[0], 2), C(s[1], 2), C(s[0], 2),
        C(h[1], 1), C(h[0], 1), C(m[1], 1), C(m[0], 1), C(s[1], 1), C(s[0], 1),
        C(h[1], 0), C(h[0], 0), C(m[1], 0), C(m[0], 0), C(s[1], 0), C(s[0], 0)
    );  

    return 0;
}
