#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dg[maxn], pts[maxn];
vector<ll> adj[maxn], alv[maxn];
queue<ll> q;
bool elim[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            dg[i] = 0; pts[i] = 0;
            adj[i].clear(); alv[i].clear();
            elim[i] = false;
        }
        for (i = 0; i < n - 1; i++) {
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
            dg[a]++; dg[b]++;
        }

        for (i = 1; i <= n; i++) {
            if (dg[i] == 1) {
                for (auto u : adj[i]) {
                    pts[u]++; alv[u].pb(i);
                }
            }
        }

        for (i = 1; i <= n; i++) {
            if (pts[i] >= k) q.push(i);
        }

        res = 0;
        while (!q.empty()) {
            /* for (i = 1; i <= n; i++) {
                cout << "node = " << i << nl;
                cout << "dg = " << dg[i] << nl;
                cout << "pts = " << pts[i] << nl;
                cout << "elim = " << elim[i] << nl;
                cout << nl;
            } */
            a = q.front(); q.pop();
            // cout << a << ' ' << elim[a] << nl;
            if (pts[a] < k) continue;
            if (elim[a] == true) continue;
            res++;

            for (i = 0; i < k; i++) {
                b = alv[a].back(); alv[a].pop_back();
                elim[b] = true;
                pts[a]--; dg[a]--;
            }

            if (dg[a] == 1) {
                for (auto u : adj[a]) {
                    pts[u]++; alv[u].pb(a);
                    if (pts[u] >= k) q.push(u);
                }
            }

            if (pts[a] >= k) q.push(a);
        }

        cout << res << nl;
    }

    return 0;
}