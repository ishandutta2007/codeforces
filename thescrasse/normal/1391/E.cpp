// 1391E
// Pairs of Pairs

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 500010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dist[maxn], parent[maxn];
vector<ll> adj[maxn], dadj[maxn];
bool visited[maxn];

void dfs(ll s) {
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        parent[u] = s;
        dist[u] = dist[s] + 1;
        dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            visited[i] = false; adj[i].clear(); dadj[i].clear();
        }
        for (i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }

        visited[1] = true; dist[1] = 1; dfs(1);

        flag[0] = 0;
        for (i = 1; i <= n; i++) {
            dadj[dist[i]].pb(i);
            if (dist[i] >= (n + 1) / 2) flag[0] = i;
        }

        if (flag[0] == 0) {
            cout << "PAIRING" << nl;
            m = (n + 1) / 2; m += (m % 2); m /= 2;
            cout << m << nl;
            k = 0;
            for (i = 1; i <= n; i++) {
                while ((ll)dadj[i].size() >= 2) {
                    a = dadj[i].back(); dadj[i].pop_back();
                    b = dadj[i].back(); dadj[i].pop_back();
                    cout << a << ' ' << b << nl;
                    k++;
                    if (k >= m) break;
                }
                if (k >= m) break;
            }
        } else {
            cout << "PATH" << nl;
            k = flag[0];
            cout << dist[k] << nl;
            cout << k << ' ';
            while (k != 1) {
                k = parent[k]; cout << k << ' ';
            }
            cout << nl;
        }
    }

    return 0;
}