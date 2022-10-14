#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 998244353
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll b[3000500], a[3000500], c[300050], d[300500];
ll dp[55][55][55], p[55][55];
ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}
ll inv(ll x) {
    return binpow(x, MOD - 2);
}
ll ans;
vector<ll> g[300500];
ll mulg(ll x, ll y) {
    return x * y % MOD;
}
void add(ll& x, ll y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] == 0) {
            d[i] = -1;
        } else {
            d[i] = 1;
        }
    }
    ll sum = 0, sum1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (b[i] == 1) {
            sum1 += a[i];
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= i; j++) {
            if (sum + 2 * j - i < 0) {
                continue;
            }
            p[i][j] = (sum1 + j) * inv(sum + 2 * j - i) % MOD;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int l = 0; l <= m; l++) {
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= m; j++) {
                    dp[l][i][j] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                for (int l = 0; l <= i; l++) {
                    if (dp[i][j][l] == 0) {
                        continue;
                    }

                    ll cur_sum = sum + 2 * l - i;
                    ll cur_val = a[k] + j * d[k];
                    ll summ = sum1 + l - cur_val * b[k];
                    add(dp[i + 1][j + 1][l + b[k]], mulg(mulg(dp[i][j][l], inv(cur_sum)), cur_val));
                    add(dp[i + 1][j][l], mulg(mulg(dp[i][j][l], inv(cur_sum)), cur_sum - summ - cur_val));

                    add(dp[i + 1][j][l + 1], mulg(mulg(dp[i][j][l], inv(cur_sum)), summ));
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i <= m; i++) {
            for (int l = 0; l <= m; l++) {
                if (dp[m][i][l] == 0) {
                    continue;
                }
                //cout << k << " " << i << " " << l << " " << dp[m][i][l] << endl;
                ans += dp[m][i][l] * (a[k] + i * d[k]) % MOD;
            }
        }
        cout << ans % MOD << endl;
    }
    return 0;
}