#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int e[maxn], deg[maxn];
vector<int> G[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> e[i];
    while (m--) {
        int a, b; cin >> a >> b;
        G[b].push_back(a);
        ++deg[a];
    }
    queue<int> q[2];
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) q[e[i]].push(i);
    }
    int cur = 0, ans = 0;
    while (q[0].size() || q[1].size()) {
        int c = 0;
        while (q[cur].size()) {
            int now = q[cur].front(); q[cur].pop();
            if (v[now]) continue;
            v[now] = true;
            ++c;
            for (int u : G[now]) {
                --deg[u];
                if (deg[u] == 0) q[e[u]].push(u);
            }
        }
        if (c && cur == 1) ++ans;
        cur ^= 1;
    }
    cout << ans << endl;
    return 0;
}