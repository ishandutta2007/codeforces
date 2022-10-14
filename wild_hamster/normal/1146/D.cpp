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
ll dp[400500];
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b,a%b);
}
void go(ll v) {
    if (v + x <= j && dp[v+x] == 0) {
        dp[v+x] = 1;
        r++;
        go(v + x);
    }
    if (v - y >= 0 && dp[v-y] == 0) {
        dp[v-y] = 1;
        r++;
        go(v - y);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ll m;
    cin >> m >> x >> y;
    ll p = gcd(x, y);
    dp[0] = 1;
    r = 1;
    ll ans = 1;
    for (int i = 1; i <= min(m, max(x, y) * 2); i++) {
        j = i;
        if (i >= x && dp[i-x] == 1) {
            dp[i] = 1;
            r++;
            go(i);
        }
        ans += r;
    }
    if (max(x, y) * 2 >= m) {
        cout << ans << endl;
        return 0;
    }
    ll st = max(x, y) * 2 + 1;
    ll xx = (m / p) * p;
    while (st % p != 0 && st <= m) {
        ans += st / p + 1;
        st++;
    }
    if (st > m) {
        cout << ans << endl;
        return 0;
    }
    st /= p;
    ans += (xx /p + st + 1) * (xx / p - st) / 2 * p;
    while (xx <= m) {
        ans += xx / p + 1;
        xx++;
    }
    cout << ans << endl;
    return 0;
}