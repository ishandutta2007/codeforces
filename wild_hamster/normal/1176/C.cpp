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
ll a[100500], b[500500], c[100500];
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
ll t[6] = {4,8,15,16,23,42};
vector<ll> g[6];
ll pos[6];
int main() {
    for (int i = 0; i < 6; i++) {
        a[t[i]] = i;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        b[i] = a[x];
        g[b[i]].push_back(i);
    }

    for (int i = 0; i < g[0].size(); i++) {
        ll cur_pos = g[0][i];
        for (int j = 1; j < 6; j++) {
            while (pos[j] < g[j].size()) {
                if (g[j][pos[j]] > cur_pos) {
                    cur_pos = g[j][pos[j]];
                    break;
                } else {
                    pos[j]++;
                }
            }

            if (pos[j] == g[j].size()) {
                cout << n - 6 * i << endl;
                return 0;
            }
            pos[j]++;
        }
    }
    cout << n - (int)(g[0].size()) * 6 << endl;
    return 0;
}