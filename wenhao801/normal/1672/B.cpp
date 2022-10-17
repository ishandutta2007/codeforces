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

char s[200200];

int main () {
    int T = read();
    while (T--) {
        scanf("%s", s + 1); int n = strlen(s + 1);
        int i, j, now = 0;
        for (i = 1; i <= n; i++) {
            if (s[i] == 'A') ++now;
            else {
                if (now) --now;
                else break;
            }
        }
        if (i <= n || s[n] == 'A') puts("NO"); else puts("YES");
    }
    return 0;
}