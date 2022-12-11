#include <bits/stdc++.h>

using namespace std;


#define int long long
const int N = 2e5 + 10;

vector<pair<int, int>> adj[N];
int qu[N];
long long d[N];
int lv[N];
int pa[N];

long long sub[N];
long long f[N];
int n;


void BFS(int head) {
    qu[1] = head;
    d[head] = 0;
    lv[head] = 0;
    pa[head] = -1;
    for(int j = 1, pos = 1; j <= n; j++) {
        int u = qu[j];
        for(auto i : adj[u]) {
            int v, w; tie(v, w) = i;
            if (v == pa[u]) continue;
            pa[v] = u;
            lv[v] = lv[u] + 1;
            d[v] = d[u] + w;
            qu[++pos] = v;
        }
    }
}
pair<long long, int> DFS(int u, int par) {
    long long ans = 0;
    int odd = 1;
    for(auto i : adj[u]) if (i.first != par) {
        auto res = DFS(i.first, u);
        ans += res.first;
        if (res.second % 2) ans += i.second;
        odd += res.second;
    }
    return {ans, odd};
}
void solve() { 
    BFS(1);
    for(int i = n; i >= 1; i--) {
        int u = qu[i];
        sub[u] = 1;
        f[u] = 0;
        for(auto j : adj[u]) {
            int v, w; tie(v, w) = j;
            if (v == pa[u]) continue;
            sub[u] += sub[v];
            f[u] += f[v] + sub[v] * w;
        }
    }

    long long G = DFS(1, -1).first, B = 0;
    for(int i = 1; i <= n; i++) {
        int u = qu[i];
        int worst = n - sub[u];
        for(auto j : adj[u]) {
            int v, w; tie(v, w) = j;
            if (v == pa[u]) continue;
            worst = max(worst, sub[v]);
            f[v] += (f[u] - f[v] - sub[v] * w) + (n - sub[v]) * w;
        }

        if (worst <= n / 2) 
            B = max(B, f[u]);
    }




    cout << G << " " << B << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test;
    cin >> test;
    while (test--) { 
        cin >> n; n *= 2;
        for(int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        solve();
        for(int i = 1; i <= n; i++) adj[i].clear();
    }
}