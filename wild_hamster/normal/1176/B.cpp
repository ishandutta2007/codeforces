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
ll a[100500], b[100500], c[100500];
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
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 3; i++) {
            a[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            a[x % 3]++;
        }
        ll ans =  a[0] + min(a[2], a[1]);
        ll p = min(a[2], a[1]);
        ans += (a[2] - p) / 3 + (a[1] - p) / 3;
        cout << ans << endl;
    }
    return 0;
}