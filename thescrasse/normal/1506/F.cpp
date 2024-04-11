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
vector<array<ll, 2>> v;

ll cst(ll a, ll b, ll c, ll d) {
    // cout << "cst " << a _ b _ c _ d << nl;
    ll k = b + c - a - d;
    if (k == 0) {
        if ((a + b) % 2) return 0;
        else return c - a;
    }

    if ((a + b) % 2 == 0) a++;
    k = d - b; a += k; b += k;
    return ((c - a + 1) / 2);
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
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> b[i];
        }

        v.clear(); v.pb({-1, -1}); v.pb({1, 1});
        for (i = 1; i <= n; i++) v.pb({a[i], b[i]});

        sort(v.begin(), v.end());
        // for (auto u : v) cout << u[0] _ u[1] << nl;

        res = 0; n++;
        for (i = 1; i <= n - 1; i++) {
            res += cst(v[i][0], v[i][1], v[i + 1][0], v[i + 1][1]);
        }

        cout << res << nl;
    }

    return 0;
}