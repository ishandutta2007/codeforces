#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll  q, good[1500050], b[505000], p[500500], prime[500500], ans;
ll dp[99][10050], invf[10050];
ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2 == 0) {
        return tmp;
    }
    return x * tmp % MOD;
}

ll inv(ll x) {
    return binpow(x % MOD, MOD-2);
}

ll count_dp(ll m, ll v) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= m; j++) {
            for (int l = j; l <= m; l++) {
                dp[l][i] = (dp[l][i] + dp[j][i-1] * invf[m - j + 1]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = (ans + dp[i][k] * binpow(v % MOD, m-i))%MOD;
    }
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    for (int i = 1; i <= 1000; i++)
        invf[i] = binpow(i, MOD-2);
    cin >> n >> k;
    m = n;
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        ll cnt = 0;
        ll p = 1;
        while (m % i == 0) {
            m /= i;
            cnt++;
            p *= i;
        }
        if (cnt > 0) {
            ans = ans * count_dp(cnt, i) % MOD;
        }
    }
    ans = ans * count_dp(1, m) % MOD;
    cout << ans << endl;
    return 0;
}