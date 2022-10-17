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

#define ll long long
const int MAXN = 200200;
#define pii pair<int, int>
#define fr first
#define se second

int n, m, q;
vector <pii> E[MAXN];
vector <int> c[MAXN];

int dfn[MAXN], low[MAXN], cnt;
int stk[MAXN], top, col[MAXN], cc; bool vis[MAXN];
void tarjan (int x) {
    dfn[x] = low[x] = ++cnt; stk[++top] = x; vis[x] = 1;
    for (auto i: E[x]) {
        if (!dfn[i.fr]) {
            tarjan(i.fr);
            low[x] = min(low[x], low[i.fr]);
        }
        else if (vis[i.fr]) low[x] = min(low[x], low[i.fr]);
    }
    if (dfn[x] == low[x]) {
        col[x] = ++cc; vis[x] = 0; c[cc].push_back(x);
        while (stk[top] != x) vis[stk[top]] = 0, col[stk[top]] = cc, c[cc].push_back(stk[top]), --top;
        --top;
    }
}

ll dep[MAXN], cur, ans[MAXN];
void dfs (int x) {
    vis[x] = 1;
    for (auto i: E[x]) if (col[i.fr] == cur) {
        if (!vis[i.fr]) {
            dep[i.fr] = dep[x] + i.se;
            dfs(i.fr);
        }
        else ans[cur] = __gcd(ans[cur], dep[x] - dep[i.fr] + i.se);
    }
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        E[u].push_back(make_pair(v, w));
    }
    for (i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    for (cur = 1; cur <= cc; cur++) dfs(c[cur].back());
    int q = read();
    while (q--) {
        ll x = read(), s = read(), t = read(); s = (t - s) % t;
        if (!ans[col[x]]) { puts(s ? "NO" : "YES"); continue; }
        ll tmp = __gcd(ans[col[x]], t);
        if (s % tmp == 0) puts("YES"); else puts("NO");
    }
    return 0;
}