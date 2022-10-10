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
ll l, r, c;
array<ll, 2> mn, mx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; mn = {INF, INF}; mx = {-INF, -INF};
        for (i = 1; i <= n; i++) {
            cin >> l >> r >> c;
            if (l < mn[0] || r > mx[0]) res = INF;
            if (l <= mn[0] && r >= mx[0]) {
                res = min(res, c);
            }
            mn = min(mn, {l, c}); mx = max(mx, {r, -c});
            res = min(res, mn[1] - mx[1]);
            cout << res << nl;
        }
    }

    return 0;
}