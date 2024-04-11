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
ll b[3000500], c[3000500];
ll fac[3000500];
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
ll ans;
vector<ll> g[300500];
void dfs(ll v, ll p = -1) {
    ll k = 0;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        k++;
        dfs(to, v);
    }
    ans = ans * fac[k] % MOD;
    if (v != 1) {
        ans = ans * (k + 1) % MOD;
    }
}
int main() {
    fac[0] = 1;
    for (int i = 1; i <= 200500; i++) {
        fac[i] = fac[i-1] * i % MOD;
    }
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ans = n;
    dfs(1);
    cout << ans << endl;
    return 0;
}