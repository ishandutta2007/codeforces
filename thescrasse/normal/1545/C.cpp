#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn], r, c, v, d, z;
bool vis[maxn];
vector<ll> gr[maxn], rs;
priority_queue<array<ll, 3>> pq;
set<ll> adj[510][510];
set<ll> st, bd;

void reset() {
    ll i, j, k;
    st.clear(); bd.clear(); rs.clear();
    while (!pq.empty()) pq.pop();
    for (j = 1; j <= m; j++) {
        for (k = 1; k <= m; k++) {
            adj[j][k].clear();
        }
    }
    for (i = 1; i <= n; i++) {
        gr[i].clear(); vis[i] = false;
    }
}

void dfs(ll s, ll c) {
    if (vis[s]) return;
    vis[s] = true;
    if (c == 0) rs.pb(s);
    for (auto u : gr[s]) dfs(u, c ^ 1);
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
        cin >> m; n = 2 * m; reset();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> mt[i][j];
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                adj[j][mt[i][j]].insert(i);
            }
        }

        /* for (i = 1; i <= m; i++) {
            for (j = 1; j <= m; j++) {
                cout << i _ j << ": ";
                for (auto u : adj[i][j]) cout << u << ' ';
                cout << nl;
            }
        } */

        for (j = 1; j <= m; j++) {
            for (k = 1; k <= m; k++) {
                pq.push({(ll)-adj[j][k].size(), j, k});
            }
        }

        // o[0] = dist, o[1] = col, o[2] = val
        while (!pq.empty()) {
            array<ll, 3> o = pq.top(); pq.pop();
            d = -o[0]; c = o[1]; v = o[2];
            // cout << "pq " << d _ c _ v << nf;
            if (d != adj[c][v].size()) continue;
            if (d == 0) continue;
            if (d >= 2) break;
            r = (*adj[c][v].begin());
            if (st.find(r) != st.end()) continue;
            st.insert(r);
            // cout << "r = " << r << nf;
            for (j = 1; j <= m; j++) {
                for (auto u : adj[j][mt[r][j]]) {
                    // cout << "j, u = " << j _ u << nf;
                    if (u == r) continue;
                    if (bd.find(u) != bd.end()) continue;
                    bd.insert(u);
                    for (k = 1; k <= m; k++) {
                        if (j == k) continue;
                        // cout << "k = " << k << nf;
                        adj[k][mt[u][k]].erase(u);
                        pq.push({(ll)-adj[k][mt[u][k]].size(), k, mt[u][k]});
                    }
                }
            }
        }

        /* cout << "st" << nl;
        for (auto u : st) cout << u << ' ';
        cout << nl; */

        for (j = 1; j <= m; j++) {
            for (k = 1; k <= m; k++) {
                if (adj[j][k].size() != 2) continue;
                z = 0;
                for (auto u : adj[j][k]) {
                    flag[z] = u; z++;
                }
                if (st.find(flag[0]) != st.end()) continue;
                if (bd.find(flag[0]) != bd.end()) continue;
                if (st.find(flag[1]) != st.end()) continue;
                if (bd.find(flag[1]) != bd.end()) continue;
                gr[flag[0]].pb(flag[1]); gr[flag[1]].pb(flag[0]);
            }
        }

        /* for (i = 1; i <= n; i++) {
            cout << i << ": ";
            for (auto u : gr[i]) cout << u << ' ';
            cout << nl;
        } */

        for (auto u : st) rs.pb(u);
        res = 1;
        for (i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (st.find(i) != st.end()) continue;
            if (bd.find(i) != bd.end()) continue;
            res = (2 * res) % mod;
            dfs(i, 0);
        }

        cout << res << nl;
        for (auto u : rs) cout << u << ' ';
        cout << nl;
    }

    return 0;
}