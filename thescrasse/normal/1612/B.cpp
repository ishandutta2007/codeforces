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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
vector<ll> x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> a >> b; n /= 2; x.clear(); y.clear();
        for (i = 1; i <= a - 1; i++) y.pb(i);
        if (a < b + 1) x.pb(a);
        if (b > a - 1) y.pb(b);
        for (i = b + 1; i <= 2 * n; i++) x.pb(i);

        for (i = a + 1; i <= b - 1; i++) {
            if (x.size() < y.size()) x.pb(i);
            else y.pb(i);
        }

        if (x.size() != n || y.size() != n) {
            cout << -1 << nl; continue;
        }

        for (auto u : x) cout << u << ' ';
        for (auto u : y) cout << u << ' ';
        cout << nl;
    }

    return 0;
}