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
ll q, l, r, ps[maxn], ss[maxn], pm[maxn][2], sm[maxn][2], mn, mx;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> q >> s;
        for (i = 0; i < n; i++) {
            if (s[i] == '+') a[i + 1] = 1;
            else a[i + 1] = -1;
        }

        for (i = 1; i <= n + 1; i++) {
            ps[i] = 0; ss[i] = 0;
            pm[i][0] = INF; sm[i][0] = INF;
            pm[i][1] = -INF; sm[i][1] = -INF;
        }

        for (i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + a[i];
            pm[i][0] = min(pm[i - 1][0], ps[i]);
            pm[i][1] = max(pm[i - 1][1], ps[i]);
        }
        for (i = n; i >= 1; i--) {
            // ss[i] = ss[i + 1] + a[i];
            sm[i][0] = min(sm[i + 1][0], ps[i]);
            sm[i][1] = max(sm[i + 1][1], ps[i]);
        }

        /* for (i = 1; i <= n; i++) {
            cout << i _ ps[i] _ pm[i][0] _ pm[i][1] _ sm[i][0] _ sm[i][1] << nl;
        } */

        while (q--) {
            cin >> l >> r;
            mx = max({(ll)0, pm[l - 1][1], ps[l - 1] - ps[r] + sm[r + 1][1]});
            mn = min({(ll)0, pm[l - 1][0], ps[l - 1] - ps[r] + sm[r + 1][0]});
            // cout << mn _ mx << nl;
            cout << mx - mn + 1 << nl;
        }
    }

    return 0;
}