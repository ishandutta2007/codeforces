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
        cin >> n; mp.clear(); res = 0;
        for (i = 1; i <= n; i++) {
            cin >> a; mp[a - i]++;
        }

        for (auto u : mp) {
            k = u.second;
            res += (k * (k - 1)) / 2;
        }

        cout << res << nl;
    }

    return 0;
}