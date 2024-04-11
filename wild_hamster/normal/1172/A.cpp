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
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll b[3000500], c[3000500];
ll a[3000500];
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

bool check(ll x) {

    for (int i = 0; i < n; i++) {
        c[a[i]] = 1;
    }
    for (int i = 1; i < n - x + 1; i++) {
        if (b[i + x - 1] != i) {
            return false;
        }
    }
    for (int i = n - x + 1; i <= n; i++) {
        if (c[i] != 1) {
            return false;
        }
        c[b[i - (n - x + 1)]] = 1;
    }
    return true;
}
bool can(ll x) {
    for (int i = 1; i <= n; i++) {
        c[i] = 0;
    }
        for (int i = 0; i < n; i++) {
            c[a[i]] = 1;
        }
        for (int i = 0; i < x - n; i++) {
            c[b[i]] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (c[i] != 1) {
                return false;
            }
            c[b[i + x - n - 1]] = 1;
        }
    return true;
}
int main() {
    cin >> n;
    ll pos = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (b[i] == 1) {
            pos = i;
        }
    }
    if (check(pos)) {
        cout << pos << endl;
        return 0;
    }
    ll l = n, r = 2 * n;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (can(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}