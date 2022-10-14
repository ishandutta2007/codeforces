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
ll a[200505], b[200505], c[200500];
vector<ll> g[20050];
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> MOD;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c, c+n);
    reverse(c, c+n);
    for (int i = 0; i < n; i++) {
        x = c[i];
        x %= MOD;
        ll y = (-x + MOD) % MOD;
        //cout << y << "\n";
        for (int j = 0; j < MOD; j++) {
            a[y] += b[j];
            //if (b[j])
            //cout << y << " " << j << " " << b[j] << "\n";
            y++;
            if (y == MOD) {
                y = 0;
            }
        }

        b[x]++;
    }
    ll x = 1;
    for (int i = 0; i < MOD; i++) {
        x = x * binpow(i, a[i]) % MOD;
    }
    cout << x << "\n";

    return 0;
}