#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
vector<pair<int, int>> G[maxn];
int d1[maxn], d2[maxn];
bool v[maxn], sp[maxn];

int dfs1(int now) {
    v[now] = true;
    int c = 1;
    for (auto e : G[now]) if (!v[e.first]) {
        if (e.second == 0) c += dfs1(e.first);
        else if (e.second > 0) d1[e.second] = 0, c += dfs1(e.first);
        else d1[-e.second] = 1, c += dfs1(e.first);
    }
    return c;
}

int dfs2(int now) {
    v[now] = true;
    int c = 1;
    for (auto e : G[now]) if (!v[e.first]) {
        if (e.second == 0) c += dfs2(e.first);
        else if (e.second > 0) d2[e.second] = 1;
        else d2[-e.second] = 0;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s; cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) G[a].emplace_back(b, 0);
        else G[a].emplace_back(b, i), G[b].emplace_back(a, -i), sp[i] = true;
    }
    int ans1 = dfs1(s);
    memset(v, false, sizeof(v));
    int ans2 = dfs2(s);
    cout << ans1 << endl;
    for (int i = 1; i <= m; ++i) if (sp[i]) cout << (d1[i] ? '-' : '+'); cout << endl;
    cout << ans2 << endl;
    for (int i = 1; i <= m; ++i) if (sp[i]) cout << (d2[i] ? '-' : '+'); cout << endl;
    return 0;
}