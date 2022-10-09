#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define ld long double
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, num, mod;

ll fxp(ll b, ll e) {
    ll k;
    if (e == 0) return 1;
    if (e % 2 == 0) {
        k = fxp(b, e / 2);
        return (k * k) % mod;
    } else {
        k = fxp(b, e - 1);
        return (b * k) % mod;
    }
}

ll bnm(ll n, ll d) {
    ll i, res;
    res = 1;
    for (i = n; i > n - d; i--) {
        res *= i; res %= mod;
    }
    for (i = 1; i <= d; i++) {
        res *= fxp(i, mod - 2); res %= mod;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 998244353;
    cin >> n >> k; k--;
    for (i = 1; i <= n; i++) {
        num = (n / i) - 1;
        // cout << num << ' ' << k << endl;
        if (num >= k) {
            res += bnm(num, k); res %= mod;
        }
    }

    cout << res;

    return 0;
}