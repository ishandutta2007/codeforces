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

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        a[i] = mp(x, y);
    }

    for (int i = 0; i < n/2; i++) {
        good.clear();
        for (int i = 1; i <= n; i++) {
            w[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            if (!used[a[i].X] && !used[a[i].Y]) {
                w[a[i].X]++;
                w[a[i].Y]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (w[i] == 1 && !used[i]) {
                good.push_back(i);
            }
        }
        ll q = query(good[0], good[1]);
        if (q == good[0] || q == good[1]) {
            cout << "! " << q << "\n";
            fflush(stdout);
            return 0;
        }
        used[good[0]] = used[good[1]] = 1;
        if (i == n / 2 - 1) {
            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    cout << "! " << i << "\n";
                    fflush(stdout);
                    return 0;
                }
            }
        }
    }

    return 0;
}