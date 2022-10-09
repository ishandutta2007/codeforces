#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
vector<ll> adj[maxn], v;

void reset() {
    ll i;
    v.clear(); k = 0;
    for (i = 1; i <= n; i++) adj[i].clear();
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
        cin >> n; reset();
        for (i = 1; i <= n; i++) {
            cin >> a[i]; b[i] = 0;
            if (adj[a[i]].empty()) k++;
            adj[a[i]].pb(i);
        }

        /* for (i = 1; i <= n; i++) {
            cout << i << ": ";
            for (auto u : adj[i]) cout << u << ' ';
            cout << nl;
        } */

        if (k == n - 1) {
            for (i = 1; i <= n; i++) {
                if (adj[i].empty()) m = i;
            }
            for (i = 1; i <= n; i++) {
                if (adj[i].empty()) continue;
                if (adj[i].size() == 1) {
                    b[adj[i][0]] = i;
                } else if (adj[i][0] == m) {
                    b[m] = i;
                } else {
                    b[adj[i][1]] = i;
                }
            }
            for (i = 1; i <= n; i++) {
                if (b[i] == 0) b[i] = m;
            }
        } else {
            for (i = 1; i <= n; i++) {
                if (!adj[i].empty()) b[adj[i][0]] = i;
            }

            /* for (i = 1; i <= n; i++) cout << b[i] << ' ';
            cout << nl; */

            if (k != n) {
                for (i = 1; i <= n; i++) {
                    if (b[i] == 0) v.pb(i);
                }
                m = v.size();
                for (i = 0; i <= m - 1; i++) {
                    if (adj[v[i]].empty()) {
                        b[v[(i + 1) % m]] = v[i]; adj[v[i]].pb(-1);
                    }
                }

                m = 1;
                for (i = 1; i <= n; i++) {
                    if (b[i] != 0) continue;
                    while (!adj[m].empty()) m++;
                    b[i] = m; m++;
                }
            }
        }

        cout << k << nl;
        for (i = 1; i <= n; i++) cout << b[i] << ' ';
        cout << nl;
    }

    return 0;
}