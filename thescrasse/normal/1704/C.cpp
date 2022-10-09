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
        ll n, m; cin >> n >> m;
        vector<ll> pos(m, 0);
        for (ll i = 0; i < m; i++) cin >> pos[i];
        sort(pos.begin(), pos.end());

        vector<ll> dist;
        for (ll i = 0; i < m; i++) dist.pb((pos[(i + 1) % m] - pos[i] + 2 * n - 1) % n);

        sort(dist.begin(), dist.end());
        /* for (auto u : dist) cout << u << ' ';
        cout << nl; */
        ll moves = 0;
        ll infected = n;
        while (!dist.empty()) {
            auto s = max((ll)0, dist.back() - 2 * moves);
            if (s == 0) break;
            if (s <= 2) {
                infected--; break;
            }

            infected -= (s - 1); moves += 2;

            dist.pop_back();
        }

        cout << infected << nl;
    }

    return 0;
}