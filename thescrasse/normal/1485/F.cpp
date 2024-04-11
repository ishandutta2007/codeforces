#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b[maxn], tt;
map<ll, ll> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n; mp.clear();
        for (i = 1; i <= n; i++) {
            cin >> b[i];
        }

        mp[0] = 1; tt = 1; k = 0;
        for (i = 1; i <= n; i++) {
            a = mp[k]; mp[k] = tt; k -= b[i];
            tt = (2 * tt - a + mod) % mod;
        }

        cout << tt << nl;
    }

    return 0;
}