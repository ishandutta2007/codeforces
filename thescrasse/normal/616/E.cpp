// 616E
// Sum of Remainders

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, s, l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m; s = sqrt(n);

    res = 0;
    if (m > n) {
        k = n % mod; k *= ((m - n) % mod); k %= mod;
        res += k; m = n;
    }

    for (i = n / m; i <= s; i++) {
        l = n / i - n / (i + 1); l %= mod;
        k = (l * (l - 1)) / 2; k %= mod;
        k *= i; k %= mod;
        k += (l * ((n % (n / i)) % mod)); k %= mod;
        // cout << i << ' ' << k << nl;
        res += k;

        if (i == n / m) {
            l = n / i - m; l %= mod;
            k = (l * (l - 1)) / 2; k %= mod;
            k *= i; k %= mod;
            k += (l * ((n % (n / i)) % mod)); k %= mod;
            // cout << i << ' ' << k << nl;
            res += (mod - k);
        }

        res %= mod;
    }

    // cout << "---" << nl;

    for (i = 1; i <= n / (s + 1); i++) {
        if (i <= m) {
            // cout << i << ' ' << n % i << nl;
            res += (n % i); res %= mod;
        }
    }

    cout << res;

    return 0;
}