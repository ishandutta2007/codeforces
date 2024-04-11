#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int a[maxn], b[maxn], low[maxn], tin[maxn], t, br;
int p[maxn], q[maxn];
vector<pair<int, int>> G[maxn];
size_t ptr[maxn];
bool v[maxn];

void tarjan(int now, int fa) {
    tin[now] = low[now] = ++t;
    for (auto u : G[now]) if (u.first != fa) {
        if (tin[u.first]) {
            low[now] = min(low[now], tin[u.first]);
            continue;
        }
        tarjan(u.first, now);
        low[now] = min(low[now], low[u.first]);
        if (low[u.first] > tin[now]) ++br;
    }
}

void dfs(int now) {
    for (; ptr[now] < G[now].size(); ++ptr[now]) {
        int to, eid;
        tie(to, eid) = G[now][ptr[now]];
        if (v[eid]) continue;
        if (a[eid] == now) p[eid] = now, q[eid] = b[eid];
        else p[eid] = now, q[eid] = a[eid];
        v[eid] = true;
        dfs(to);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        G[a[i]].emplace_back(b[i], i);
        G[b[i]].emplace_back(a[i], i);
    }
    tarjan(1, 0);
    if (br) return cout << "0" << endl, 0;
    dfs(1);
    for (int i = 0; i < m; ++i) cout << p[i] << ' ' << q[i] << endl;
    return 0;
}