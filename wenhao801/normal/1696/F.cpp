#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 110;
int n;
bool a[MAXN][MAXN][MAXN];
int fa[MAXN][MAXN], s[MAXN];
int gf(int rt, int x) { if (fa[rt][x] == x) return x; return fa[rt][x] = gf(rt, fa[rt][x]); }

char str[MAXN];
vector <int> b[MAXN];

int f[MAXN], F[MAXN]; bool act[MAXN];
int gF(int x) { if (F[x] == x) return x; return F[x] = gF(F[x]); }
int e[MAXN][MAXN];
vector <int> E[MAXN];

bool A[MAXN][MAXN][MAXN], cycle; int dep[MAXN]; vector <int> bdep[MAXN];
void dfs(int x, int f) {
    dep[x] = dep[f] + 1;
    for (auto i: E[x]) if (i != f) {
        if (dep[i]) cycle = 1;
        else dfs(i, x);
    }
}

bool solve() {
    n = read(); int i, j, k;
    for (i = 1; i < n; i++) {
        for (j = 1; j <= n - i; j++) {
            scanf("%s", str + 1);
            for (k = 1; k <= n; k++) if (str[k] == '1') a[k][i][i + j] = a[k][i + j][i] = 1;
        }
    }
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) fa[i][j] = j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) for (k = 1; k < j; k++) if (a[i][j][k]) fa[i][gf(i, j)] = gf(i, k);
        for (j = 1; j <= n; j++) s[i] += gf(i, j) == j;
        b[s[i]].push_back(i);
    }
    bool fir = 0; int acts = 0, last = 0;
    for (i = 1; i <= n; i++) F[i] = i;
    for (i = 1; i <= n; last = b[i].empty() ? last : i, i++) if (!b[i].empty()) {
        for (auto j: b[i]) act[j] = 1, ++acts;
        for (auto j: b[i]) for (int k = 1; k <= n; k++) if (act[k] && j < k) {
            ++e[j][k], ++e[k][j];
        }
        if (!fir) {
            fir = 1;
            if (b[i].size() > 2) return 0;
            if (b[i].size() == 2) E[b[i][0]].push_back(b[i][1]), E[b[i][1]].push_back(b[i][0]), f[b[i][0]] = b[i][1], f[b[i][1]] = b[i][0];
            continue;
        }
        if (acts - b[i].size() == 1) {
            for (auto j: b[i]) f[j] = b[last][0], E[j].push_back(f[j]), E[f[j]].push_back(j);
            continue;
        }
        for (auto j: b[i]) for (auto k: b[i]) if (j < k && e[j][k] == acts - 2) F[gF(j)] = gF(k);
        for (auto j: b[i]) if (gF(j) == j) {
            for (auto k: b[last]) if (a[k][f[k]][j]) { f[j] = k; break; }
        }
        for (auto j: b[i]) f[j] = f[gF(j)], E[f[j]].push_back(j), E[j].push_back(f[j]);
    }
    if (!E[0].empty()) return 0;
    cycle = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) dep[j] = 0;
        dfs(i, 0); if (cycle) return 0;
        for (j = 0; j <= n; j++) bdep[j].clear();
        for (j = 1; j <= n; j++) bdep[dep[j]].push_back(j);
        for (j = 1; j <= n; j++) {
            for (auto p: bdep[j]) for (auto q: bdep[j]) A[i][p][q] = A[i][q][p] = 1;
        }
    }
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) for (k = 1; k < j; k++) if (a[i][j][k] != A[i][j][k]) return 0;
    return 1;
}

void clear() {
    int i, j, k;
    for (i = 0; i <= n; i++) for (j = 0; j <= n; j++) for (k = 0; k <= n; k++)
        A[i][j][k] = a[i][j][k] = 0, fa[i][j] = 0, s[i] = 0, b[i].clear(), f[i] = F[i] = 0, act[i] = 0, e[i][j] = 0, E[i].clear();
}

int main () {
    int T = read(); while (T--) {
        bool res = solve();
        if (!res) puts("No"); else {
            puts("Yes");
            for (int i = 1; i <= n; i++) for (auto j: E[i]) if (j < i) printf("%d %d\n", i, j);
        }
        clear();
    }
    return 0;
}