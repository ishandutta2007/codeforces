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
    int T = read();
    while (T--) {
        int a[505] = {};
        int n = read();
        int i, j;
        for (i = 1; i <= n; i++)
            a[i] = read();
        int ans = 0;
        for (i = 1; i < n; i++) {
            if (a[i] + 1 != a[i + 1] && (a[i] != n || a[i + 1] != 1)) { ans++; break; }
        }
        for (i = 1; i < n; i++) {
            if (a[i] - 1 != a[i + 1] && (a[i] != 1 || a[i + 1] != n)) { ans++; break; }
        }
        if (ans == 2) puts("NO");
        else puts("YES");
    }
    return 0;
}