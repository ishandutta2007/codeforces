#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], c[maxn], f[maxn], x;
vector<ll> adj[maxn], stadj[maxn], rs;
set<ll> nfx;

void upd(ll p, ll x) {
    if (a[p] != b[p]) nfx.erase(p);
    a[p] = x; rs.pb(p);
    if (a[p] != b[p]) nfx.insert(p);
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
        cin >> n >> m; rs.clear(); nfx.clear();
        for (i = 1; i <= n; i++) {
            adj[i].clear(); stadj[i].clear(); f[i] = 0;
        }

        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> b[i];
            stadj[b[i]].pb(i);
            if (a[i] != b[i]) {
                adj[b[i]].pb(i); nfx.insert(i);
            }
        }
        for (i = 1; i <= m; i++) {
            cin >> c[i]; f[c[i]]++;
        }

        for (i = m; i >= 1; i--) {
            // cout << i _ c[i] _ f[c[i]] _ (ll)adj[c[i]].size() << nl;
            if (!stadj[c[i]].empty()) {
                k = stadj[c[i]][0]; break;
            }
        }
        if (i == 0) {
            cout << "NO" << nl; continue;
        }

        for (i = 1; i <= m; i++) {
            if (stadj[c[i]].empty()) {
                if (nfx.empty()) {
                    upd(k, c[i]);
                } else {
                    auto it = nfx.begin(); x = (*it);
                    upd(x, c[i]);
                }
            } else {
                if (adj[c[i]].empty()) {
                    upd(stadj[c[i]][0], c[i]);
                } else {
                    upd(adj[c[i]].back(), c[i]); adj[c[i]].pop_back();
                }
            }
        }

        if (!nfx.empty()) {
            cout << "NO" << nl; continue;
        }

        cout << "YES" << nl;
        for (auto u : rs) cout << u << ' ';
        cout << nl;
    }

    return 0;
}