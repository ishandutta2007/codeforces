#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

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
#define ld long double
const int MAXN = 55;
const ll mul = 10000, inf = 1e18;

int n; ll a[MAXN], b[MAXN];

struct tmp { ll a, b; bool operator < (const tmp &rua) const { return a < rua.a; } } t[MAXN];

ld f[MAXN][MAXN][MAXN];
#define cost(i) (S * b[i] - a[i])
void chkmax (ld &x, ld y) { x = max(x, y); }

bool check (ld S) {
    int i, j, k;
    for (i = 0; i <= n; i++) for (j = 0; j <= n; j++) for (k = 0; k <= n; k++) f[i][j][k] = -inf;
    f[0][0][0] = 0;
    for (i = 0; i < n; i++) for (j = 0; j <= n; j++) for (k = 0; k <= n; k++) if (fabs(f[i][j][k] + inf) > 0.0001) {
        if (a[i] == a[i + 1]) {
            chkmax(f[i + 1][j][max(0, k - 1)], f[i][j][k] + cost(i + 1));
            chkmax(f[i + 1][j + 1][k], f[i][j][k]);
        }
        else {
            chkmax(f[i + 1][0][max(0, j + k - 1)], f[i][j][k] + cost(i + 1));
            chkmax(f[i + 1][1][j + k], f[i][j][k]);
        }
    }
    return f[n][0][0] > -0.0001;
}

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) t[i].a = read();
    for (i = 1; i <= n; i++) t[i].b = read();
    sort(t + 1, t + n + 1);
    for (i = 1; i <= n; i++) a[i] = t[i].a, b[i] = t[i].b;
    ll L = 0, R = 1e18, ans = -1000;
    while (L <= R) {
        ll mid = (L + R) >> 1;
        if (check(((ld)(mid)/((ld)mul)))) R = mid - 1, ans = mid;
        else L = mid + 1;
    }
    printf("%lld\n", ans % 10 == 0 ? (ans / 10) : (ans / 10 + 1));
    return 0;
}