#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define PB push_back
#define ar2 array<int, 2>
const int N = 2e5 + 5;
const int INF = 1e9;

int T, n, q, s, d, x, y;
int a[N], group[N], conn_k[N];
vector<int> st[N];
vector<ar2> g[N];
set<ar2> nodes, line;

void update(int u0, int pos, int &dist, int &u, int &v) {
    auto iter = line.lower_bound({pos, 0});
    if (iter != line.end()) {
        ar2 ele = *iter;
        if (abs(pos - ele[0]) < dist)
            dist = abs(pos - ele[0]), u = u0, v = ele[1];
    }
    if (iter != line.begin()) {
        iter--;
        ar2 ele = *iter;
        if (abs(pos - ele[0]) < dist)
            dist = abs(pos - ele[0]), u = u0, v = ele[1];
    }
}

void dfs(int x, int fa, int ma) {
    conn_k[x] = ma;
    for (auto ele : g[x]) {
        if (ele[0] != fa)
            dfs(ele[0], x, max(ma, ele[1]));
    }
}

int main() {
    scanf("%d%d%d%d", &n, &q, &s, &d);
    rep(i, 1, n) scanf("%d", a + i), st[i].PB(i), group[i] = i;

    rep(i, 1, n) nodes.insert({1, i}), line.insert({a[i], i});

    rep(i, 1, n - 1) {
        int x = (*nodes.begin())[1];
        for (auto y : st[x])
            line.erase({a[y], y});
        int dist = INF, u, v;
        for (auto y : st[x]) {
            update(y, a[y] + d, dist, u, v);
            update(y, a[y] - d, dist, u, v);
        }
        for (auto y : st[x])
            line.insert({a[y], y});
        g[u].PB({v, dist}), g[v].PB({u, dist});

        int fa = group[v];
        nodes.erase({st[x].size(), x}), nodes.erase({st[fa].size(), fa});
        for (auto y : st[x])
            st[fa].PB(y), group[y] = fa;
        st[x].clear();
        nodes.insert({st[fa].size(), fa});
    }

    dfs(s, 0, 0);
    rep(i, 1, q) {
        scanf("%d%d", &x, &y);
        printf(conn_k[x] <= y ? "YES\n" : "NO\n");
    }
    return 0;
}