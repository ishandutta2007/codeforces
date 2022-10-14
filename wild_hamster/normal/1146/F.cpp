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
ll n,m,k, y, z, l, i, j, x, r;
ll a[100500], b[100500];
vector<ll> g[200500];
ll dp[200500][2];
ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y/2);
    tmp = tmp*tmp%MOD;
    if (y % 2)
        return x * tmp % MOD;
    return tmp;
}

ll inv(ll x) {
    return binpow(x, MOD-2);
}
void dfs(ll v, ll p = -1) {
    ll k = 0;
    ll prod1 = 1;
    ll prod = 1;
    ll sum = 0;
    ll sum1 = 0;
    for (auto to : g[v]) {
        if (to == p)
            continue;
        dfs(to, v);
        prod1 = prod1 * (dp[to][0] + dp[to][1]) % MOD;
        prod = prod * (dp[to][1]) % MOD;
        sum = (sum + dp[to][0]) % MOD;
        sum1 = (sum1 + dp[to][1]) % MOD;
        k++;
    }
    if (k == 0) {
        dp[v][0] = 1;
        dp[v][1] = 1;
        return;
    }
    ll mag = prod1;
    for (auto to : g[v]) {
        if (to == p)
            continue;
        mag = (mag - prod * inv(dp[to][1]) % MOD * dp[to][0] % MOD) + MOD;
        mag %= MOD;
    }
    dp[v][0] = (prod1 - prod + MOD + MOD) % MOD;
    dp[v][1] = mag;

}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1);
    cout << dp[1][1] << endl;
    return 0;
}