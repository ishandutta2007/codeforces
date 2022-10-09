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

    cin >> n; mp[0] = 1;
    for (i = 1; i <= n; i++) {
        cin >> a; k += a;
        if (mp[k] >= 1) {
            mp.clear(); mp[0]++; k = a; res++;
        }
        mp[k]++;
    }

    cout << res << nl;

    return 0;
}