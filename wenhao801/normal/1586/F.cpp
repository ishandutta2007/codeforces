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

#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 1010;
int ans[MAXN][MAXN], n, K, mx;

pii a[MAXN][MAXN];
void solve (int l, int r, int dep) {
    if (l == r) return;
    // printf("solve %d %d %d\n", l, r, dep);
    int len = r - l + 1, rem = len % K; a[dep][0].se = l - 1;
    for (int i = 1; i <= K; i++) a[dep][i].fr = a[dep][i - 1].se + 1, a[dep][i].se = a[dep][i].fr + len / K + (i <= rem) - 1;
    for (int i = 1; i <= K; i++) if (a[dep][i].fr <= a[dep][i].se) {
        for (int j = 1; j < i; j++) if (a[dep][j].fr <= a[dep][j].se) {
            for (int p = a[dep][i].fr; p <= a[dep][i].se; p++) for (int q = a[dep][j].fr; q <= a[dep][j].se; q++)
                ans[p][q] = ans[q][p] = dep, mx = max(mx, dep);
        }
    }
    for (int i = 1; i <= K; i++) if (a[dep][i].fr <= a[dep][i].se) solve(a[dep][i].fr, a[dep][i].se, dep + 1);
}

int main () {
    n = read(), K = read();
    solve(1, n, 1); printf("%d\n", mx);
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) printf("%d ", ans[i][j]);
    return 0;
}