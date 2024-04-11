#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dist[maxn], be, f, parent[maxn], s2[2], s, u;
bool visited[maxn];
vector<ll> adj[maxn];

void dfs(ll s) {
    // cout << "s = " << s << nl;
    for (auto u : adj[s]) {
        // cout << "u = " << u << nl;
        if (visited[u]) {
            if (u == parent[s]) continue;
            if (dist[u] > dist[s]) continue;
            if (flag[0] == 1) continue;
            be = min(be, dist[s] - dist[u] + 1);
            if (be <= k && flag[0] == 0) {
                s2[0] = s; s2[1] = u;
                // cout << s << ' ' << u << endl;
                flag[0] = 1;
            }
            continue;
        }
        dist[u] = dist[s] + 1;
        flag[(dist[u] % 2) + 8]++;
        if (dist[u] > m) {
            m = dist[u]; f = u;
        }
        parent[u] = s;
        visited[u] = true;
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

    flag[8] = 1; flag[9] = 0;
    cin >> n >> m >> k;
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    be = INF; m = 0; flag[0] = 0;
    dist[1] = 0; visited[1] = true; dfs(1);

    if (be <= k) {
        cout << 2 << nf;
        cout << be << nl;
        u = s2[1]; s = s2[0];
        cout << s << ' ' << flush;
        while (s != u) {
            s = parent[s];
            cout << s << ' ';
        }

        return 0;
    }

    cout << 1 << nf;
    if (be != INF) {
        cout << f << ' ';
        k--; k /= 2;
        while (k--) {
            f = parent[parent[f]];
            cout << f << ' ';
        }
    } else {
        k++; k /= 2;
        if (flag[8] >= k) {
            for (i = 1; i <= n; i++) {
                if (dist[i] % 2 == 0) {
                    cout << i << ' '; k--;
                }
                if (k == 0) break;
            }
        } else {
            for (i = 1; i <= n; i++) {
                if (dist[i] % 2 == 1) {
                    cout << i << ' '; k--;
                }
                if (k == 0) break;
            }
        }
    }

    return 0;
}