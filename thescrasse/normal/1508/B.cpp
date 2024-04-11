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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll p[maxn], l, rm;
vector<ll> rs;

void solve(ll n, ll k, ll sh) {
    // cout << "solve " << n _ k _ sh << nl;
    if (n == 0) return;
    ll ps = 0;
    for (i = 1; i <= n; i++) {
        ps += p[n - i];
        if (k <= ps) {
            // cout << "k, n - i = " << k _ n - i << nl;
            for (j = i; j >= 1; j--) rs.pb(j + sh);
            ps -= p[n - i];
            solve(n - i, k - ps, sh + i); break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    p[0] = 1; p[1] = 1;
    for (i = 2; i < maxn; i++) {
        if (i <= 63) p[i] = 2 * p[i - 1];
        else p[i] = 2 * INF;
    }

    cin >> t;
    while (t--) {
        cin >> n >> k; rs.clear();
        if (n <= 62 && k > p[n]) {
            cout << -1 << nl; continue;
        }

        solve(n, k, 0);

        for (auto u : rs) cout << u << ' ';
        cout << nl;
    }

    return 0;
}