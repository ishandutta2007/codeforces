#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, k;
int a[33];

int cnt[101];

signed main () {
    int T = read();
    while (T--) {
        n = read(), k = read();
        int i, j;
        for (i = 0; i <= 100; i++) cnt[i] = 0;
        for (i = 1; i <= n; i++) a[i] = read();
        for (i = 1; i <= n; i++) {
            int rua;
            for (rua = 0, j = a[i]; j; j /= k, rua++) cnt[rua] += j % k;
        }
        for (i = 0; i <= 100; i++) if (cnt[i] > 1) { puts("NO"); break; }
        if (i == 101) puts("YES");
    }
    return 0;
}