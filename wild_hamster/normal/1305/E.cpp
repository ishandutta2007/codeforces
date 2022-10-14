#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>
#include <assert.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll MOD;
pii a[200500];
vector<ll> g[20050];
ll w[1005];
ll used[1005];
vector<ll> deleted;
vector<vector<ll>> ans;

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

ll query(ll x, ll y) {
    cout << "? " << x << " " << y << "\n";
    fflush(stdout);
    cin >> x;
    return x;
}
vector<ll> good;
vector<ll> unused;
ll get(ll n) {
    if (n < 3) {
        return 0;
    }
    if (n % 2 == 0) {
        return ((n - 2) + 2) * (n / 2 - 1) / 2;
    }
    return ((n - 2) + 1) * (n / 2) / 2;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            cout << n + 2 + i << " ";
        }
        cout << "\n";
        return 0;
    }
    ll sum = 0;
    if (get(n) < m) {
        cout << -1 << "\n";
        return 0;
    }
    if (get(n) == m) {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " ";
        }
        return 0;
    }
    for (int i = n - 1; i >= 2; i--) {
        if (get(i) <= m) {
            for (int j = 0; j < i; j++) {
                cout << j + 1 << " ";
            }
            ll diff = m - get(i);
            cout << i + 1 + (i / 2 - diff) * 2 << " ";
            for (int j = 0; j < n - i - 1; j++) {
                cout << 1000000000 - 100000000 + 18000 * j << " ";
            }
            cout << "\n";
            break;
        }
    }

    return 0;
}