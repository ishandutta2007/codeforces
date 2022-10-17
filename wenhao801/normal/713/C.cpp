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

#define ll long long
const int MAXN = 3030;
int a[MAXN], b[MAXN], top; ll f[MAXN][MAXN];
ll abs (ll x) { return x < 0 ? (-x) : x; }

int main () {
    int n = read(), i, j;
    if (n == 1) { puts("0"); return 0; }
    for (i = 1; i <= n; i++) {
        a[i] = read() - i;
        b[++top] = a[i];
    }
    sort(b + 1, b + n + 1); top = unique(b + 1, b + n + 1) - b - 1;
    for (i = 1; i <= top; i++) f[1][i] = abs(b[i] - a[1]);
    ll ans = 1e18;
    for (i = 2; i <= n; i++) {
        for (j = 2; j <= top; j++) f[i - 1][j] = min(f[i - 1][j], f[i - 1][j - 1]);
        for (j = 1; j <= top; j++) {
            f[i][j] = f[i - 1][j] + abs(a[i] - b[j]);
            if (i == n) ans = min(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}