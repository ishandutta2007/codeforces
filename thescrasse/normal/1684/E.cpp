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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll e, lm;
vector<ll> v;
map<ll, ll> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k; a[0] = -1;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);

        e = 0; lm = -2;
        for (i = 1; i <= n; i++) {
            e += max((ll)0, a[i] - a[i - 1] - 1);
            if (e > k) {
                e -= max((ll)0, a[i] - a[i - 1] - 1);
                lm = a[i - 1] + (k - e);
                break;
            }
        }

        // cout << "lm =" _ lm << nl;

        if (lm == -2) {
            cout << 0 << nl; continue;
        }

        mp.clear();
        for (i = 1; i <= n; i++) {
            if (a[i] > lm) mp[a[i]]++;
        }

        v.clear();
        for (auto [x, y] : mp) v.pb(y);
        res = v.size();

        sort(v.begin(), v.end());

        for (auto u : v) {
            if (u <= k) {
                k -= u; res--;
            }
        }

        cout << res << nl;
    }

    return 0;
}