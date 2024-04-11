#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
vector<ll> adj[maxn], radj[maxn];
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            adj[i].clear(); radj[i].clear();
        }
        for (i = 1; i <= n; i++) adj[i].pb(0);
        for (i = 1; i <= n; i++) {
            cin >> a[i]; adj[a[i]].pb(i);
        }
        for (i = 1; i <= n; i++) adj[i].pb(n + 1);

        for (i = 1; i <= n; i++) {
            b[i] = 0;
            for (j = 1; j < adj[i].size(); j++) {
                b[i] = max(b[i], adj[i][j] - adj[i][j - 1]);
            }
            // if (i > 1) b[i] = min(b[i], b[i - 1]);
        }

        v.clear();
        for (i = 1; i <= n; i++) {
            v.pb(-b[i]); radj[b[i]].pb(i);
        }

        sort(v.begin(), v.end());

        /* for (auto u : v) cout << u << ' ';
        cout << nl; */

        k = INF;
        for (i = 1; i <= n; i++) {
            auto it = lower_bound(v.begin(), v.end(), -i);
            if (it == v.end()) {
                cout << -1 << ' '; continue;
            }
            k = min(k, radj[-(*it)][0]);
            cout << k << ' ';
        }
        cout << nl;
    }

    return 0;
}