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

ll calc(ll x) {
    ll mn = INF;
    while (x != 0) {
        mn = min(mn, x % 10); x /= 10;
    }
    return mn;
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
        if (n >= 100) cout << calc(n) << nl;
        else cout << n % 10 << nl;
    }

    return 0;
}