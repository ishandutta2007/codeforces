#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
vector<int> graf[maxn];
int d[maxn], dd[maxn];
bool adj[maxn][maxn], v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s, t; cin >> n >> m >> s >> t;
    while (m--) {
        int a, b; cin >> a >> b;
        graf[a].push_back(b); graf[b].push_back(a);
        adj[a][b] = adj[b][a] = true;
    }
    fill(d, d + maxn, maxn);
    queue<int> q; q.push(s); d[s] = 0; 
    while (q.size()) {
        int now = q.front(); q.pop();
        v[now] = true;
        for (int u : graf[now]) {
            if (!v[u]) d[u] = d[now] + 1, v[u] = true, q.push(u);
        }
    }
    memset(v, false, sizeof(v));
    fill(dd, dd + maxn, maxn);
    q.push(t); dd[t] = 0;
    while (q.size()) {
        int now = q.front(); q.pop();
        v[now] = true;
        for (int u : graf[now]) {
            if (!v[u]) dd[u] = dd[now] + 1, v[u] = true, q.push(u);
        }
    }
    int dst = d[t];
    int ans = 0;
    // for (int i = 1; i <= n; ++i) cout << d[i] << ' ' << dd[i] << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int ddd = min(d[i] + dd[j], dd[i] + d[j]);
            if (ddd + 1 >= dst && !adj[i][j]) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}