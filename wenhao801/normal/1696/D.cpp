#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 500500;
int n, a[MAXN][22], b[MAXN][22], lg2[MAXN], val[MAXN];
int mx (int l, int r) { int len = lg2[r - l + 1], u = a[l][len], v = a[r - (1 << len) + 1][len]; return val[u] > val[v] ? u : v; }
int mn (int l, int r) { int len = lg2[r - l + 1], u = b[l][len], v = b[r - (1 << len) + 1][len]; return val[u] < val[v] ? u : v; }

int solve (int l, int r) {
    if (l == r) return 0;
    int MX = mx(l, r), MN = mn(l, r);
    if (MX == l && MN == r) return 1;
    if (MN == l && MX == r) return 1;
    if (MX < MN) return solve(l, MX) + 1 + solve(MN, r);
    else return solve(l, MN) + 1 + solve(MX, r);
}

int main () {
    lg2[0] = -1;
    for (int i = 1; i < MAXN; i++) lg2[i] = lg2[i >> 1] + 1;
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) {
            val[i] = read();
            a[i][0] = b[i][0] = i;
        }
        for (i = 1; i <= 20; i++) for (j = 1; j + (1 << i) - 1 <= n; j++) {
            int u = a[j][i - 1], v = a[j + (1 << (i - 1))][i - 1];
            if (val[u] > val[v]) a[j][i] = u; else a[j][i] = v;
            u = b[j][i - 1], v = b[j + (1 << (i - 1))][i - 1];
            if (val[u] < val[v]) b[j][i] = u; else b[j][i] = v;
        }
        printf("%d\n", solve(1, n));
    }
    return 0;
}