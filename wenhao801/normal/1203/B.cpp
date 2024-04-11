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

int n;
int a[1010] = {};

int main () {
    int T = read();
    while (T--) {
        n = read() * 4;
        int i, j;
        for (i = 1; i <= n; i++)
            a[i] = read();
        sort(a + 1, a + n + 1);
        int s = a[1] * a[n];
        bool ans = true;
        for (i = 1; i <= n; i += 2) {
            if (a[i] != a[i + 1] || a[n - i + 1] != a[n - i] || a[i] * a[n - i + 1] != s) {
                ans = false;
                break;
            }
        }
        if (ans) puts("YES");
        else puts("NO");
    }
    return 0;
}