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
        ll k = 0;
        while (n % 5 == 0) {
            n = n * 4 / 5;
            k++;
        }
        while (n % 3 == 0) {
            n = n * 2 / 3;
            k++;
        }
        while (n % 2 == 0) {
            n /= 2;
            k++;
        }
        if (n == 1) {
            cout << k << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}