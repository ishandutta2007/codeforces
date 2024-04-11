#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1010000;
int n, m; string a[MAXN];
int q; vector <int> f[MAXN];
int ans[MAXN], lg2[MAXN];

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) cin >> a[i];
    lg2[0] = -1;
    for (i = 1; i <= m; i++) lg2[i] = lg2[i >> 1] + 1;
    for (i = 2; i <= n; i++) for (j = 1; j < m; j++) {
        if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X') ans[j]++;
    }
    for (j = 1; j < m; j++) ans[j] += ans[j - 1];
    int q = read(); while (q--) {
        int l = read() - 1, r = read() - 1;
        puts(ans[l] == ans[r] ? "YES" : "NO");
    }
    return 0;
}