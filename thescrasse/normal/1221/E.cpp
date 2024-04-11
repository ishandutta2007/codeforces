// 1221E
// Game With String

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c, d;
string s;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> a >> b >> s; s = s + 'X'; n = s.size(); v.clear();
        k = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == 'X') {
                if (k != 0) {
                    if (k >= b) v.pb(k);
                    k = 0;
                }
            } else {
                k++;
            }
        }

        /* for (auto u : v) cout << u << ' ';
        cout << nl; */

        m = v.size(); flag[0] = 0; flag[1] = 0; flag[2] = 0;
        for (i = 0; i < m; i++) {
            if (v[i] >= b && v[i] < a) {
                flag[0] = 1;
            } else if (v[i] >= 2 * b) {
                flag[1]++; k = i;
            }
        }

        // cout << flag[0] << ' ' << flag[1] << nl;

        if (flag[0] == 1 || flag[1] >= 2) {
            cout << "NO" << nl; continue;
        } else if (flag[1] == 1) {
            k = v[k];
            for (i = 0; i <= k - a; i++) {
                c = i; d = k - a - i;
                if (c >= b && c < a) continue;
                if (d >= b && d < a) continue;
                if (c >= 2 * b || d >= 2 * b) continue;
                if ((m + (c >= a) + (d >= a)) % 2 == 0) continue;
                flag[2] = 1;
            }

            if (flag[2] == 1) cout << "YES" << nl;
            else cout << "NO" << nl;
        } else {
            if (m % 2) cout << "YES" << nl;
            else cout << "NO" << nl;
        }
    }

    return 0;
}