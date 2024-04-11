#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n + 1, 0), b(n + 1, 0), ans;
        map<ll, vector<ll>> adj;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i]; adj[a[i]].pb(i);
        }

        ans.pb(-1);
        ll curr, sign, tr = 0;
        if (!adj[0].empty()) curr = 0, sign = 0;
        else curr = n + 1, sign = 1;
        while (true) {
            ll nxt = -1;
            tr += (sign * adj[curr].size());
            for (auto u : adj[curr]) {
                if (!adj[u].empty()) nxt = u;
                else ans.pb(u);
            }

            if (nxt == -1) break;
            ans.pb(nxt); curr = nxt; sign ^= 1;
        }

        cout << tr << nl;
        for (ll i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << nl;
    }

    return 0;
}