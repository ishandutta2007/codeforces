#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int main () {
    cout << "? ";
    fflush(stdout);
    int i, j;
    for (i = 1; i <= 100; i++) {
        printf("%d ", (i << 7) + 127);
        fflush(stdout);
    }
    putchar('\n'); fflush(stdout);
    int k;
    int ans = 0;
    cin >> k;
    k = k & 127;
    ans += 127 ^ k;
    cout << "? "; fflush(stdout);
    for (i = 1; i <= 100; i++) {
        printf("%d ", (127 << 7) + i);
        fflush(stdout);
    }
    cin >> k;
    k = k & (127 << 7);
    k = k ^ (127 << 7);
    ans += k;
    printf("! %d", ans);
    fflush(stdout);
    return 0;
}