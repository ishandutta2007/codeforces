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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll f[maxn];
vector<ll> rs, adj[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; rs.clear();
        for (i = 0; i <= n; i++) {
            adj[i].clear(); adj[i].pb(-1); f[i] = 0;
        }
        for (i = 1; i <= n; i++) {
            cin >> a[i]; adj[a[i]].pb(i);
        }

        m = 0;
        for (i = 1; i <= n; i++) {
            f[a[i]]++;
            while (f[m] >= 1) m++;

            if (adj[m].back() < i) {
                // cout << "found" _ i << nl;
                rs.pb(m);
                for (j = 0; j <= m; j++) f[j] = 0;
                m = 0;
            }
        }

        cout << rs.size() << nl;
        for (auto u : rs) cout << u << ' ';
        cout << nl;
    }

    return 0;
}