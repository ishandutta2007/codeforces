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

using ll = long long;
const int MAXN = 2020, mod = 998244353;
int n; bool a[MAXN][MAXN];

namespace force {
    bool vis[MAXN];
    void dfs (int x) {
        if (vis[x]) return;
        vis[x] = 1;
        for (int i = 1; i <= n; i++) if (a[x][i]) dfs(i);
    }
    void main () {
        int ans = 1e9, cnt = 0;
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++)
                a[j][k] ^= ((i >> (j - 1)) & 1) ^ ((i >> (k - 1)) & 1);
            bool ok = 1;
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) vis[k] = 0;
                dfs(j);
                for (int k = 1; k <= n; k++) ok &= vis[k];
            }
            if (ok) {
                const int pc = __builtin_popcount(i);
                if (pc < ans) ans = pc, cnt = 1;
                else if (pc == ans) ++cnt;
            }
            for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++)
                a[j][k] ^= ((i >> (j - 1)) & 1) ^ ((i >> (k - 1)) & 1);
        }
        for (int i = 1; i <= ans; i++) cnt *= i;
        if (!cnt) puts("-1");
        else printf("%d %d\n", ans, cnt);
    }
}

int dfn[MAXN], low[MAXN], cnt; bool fail = 0;
void tarjan (int x) {
    dfn[x] = low[x] = ++cnt;
    for (int i = 1; i <= n; i++) if (a[x][i]) {
        if (!dfn[i]) {
            tarjan(i); if (fail) return;
            low[x] = min(low[x], low[i]);
        }
        else low[x] = min(low[x], dfn[i]);
    }
    if (low[x] == dfn[x])
        if (x != 1) fail = 1;
}

char str[MAXN]; int outd[MAXN], tmp[MAXN];
int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        for (j = 1; j <= n; j++) a[i][j] = str[j] == '1', outd[i] += a[i][j];
    }
    if (n <= 6) { force::main(); return 0; }
    tarjan(1);
    if (!fail && cnt == n) { puts("0 1"); return 0; }
    printf("1 "); int ans = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) tmp[j] = outd[j];
        tmp[i] = n - 1 - tmp[i];
        for (j = 1; j <= n; j++) if (i != j) {
            if (a[i][j]) ++tmp[j]; else --tmp[j];
        }
        sort(tmp + 1, tmp + n + 1);
        ll s = 0;
        for (j = 1; j <= n; j++) {
            s += tmp[j];
            if (s == 1ll * j * (j - 1) / 2) break;
        }
        if (j == n) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}