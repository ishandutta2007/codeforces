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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
set<pii> f;
ll a[2000500], b[205000], c[200500];
vector<ll> g[1005000];

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
    return binpow(x, MOD-2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        sum += k;
        for (int j = 0; j < k; j++){
            cin >> x;
            g[i].push_back(x);
            a[x]++;
        }
    }
    ll pshe = 0;
    for (int i = 0; i < n; i++) {
        ll k = g[i].size();
        for (auto x : g[i]) {
            pshe += a[x] * inv(n) % MOD * inv(k) % MOD * inv(n) % MOD;
        }
    }
    cout << pshe % MOD << "\n";
    return 0;
}