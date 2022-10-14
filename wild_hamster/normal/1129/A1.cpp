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
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll a[200500], b[200500];
vector<ll> g[100500];
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2)
        return x * tmp % MOD;
    return tmp;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        b[i] = -1;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x]++;
        if (b[x] == -1) {
            b[x] = (y-x+n) % n;
        } else {
            b[x] = min(b[x], (y-x+n)%n);
        }
    }
    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] == 0)
                continue;
            ll diff = (j-i+n);
            if (diff >= n)
                diff -= n;
            ans = max(ans, diff + (a[j] - 1) * n + b[j]);
        }
        cout << ans << " ";
    }
    return 0;
}