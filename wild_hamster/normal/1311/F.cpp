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
#define MOD 1000000000
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
pii a[200505];
vector<ll> g[20050];
ll t[500500][2];
map<ll, ll> f;

void modify(ll x, ll p, ll value) {  // set value at position p
    for (t[p += n][x] = value; p > 1; p >>= 1) t[p>>1][x] = t[p][x] + t[p^1][x];
}

ll query(ll x, ll l, ll r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++][x];
        if (r&1) res += t[--r][x];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].Y;
        f[a[i].Y] = 0;
    }
    ll s = 0;
    for (auto it = f.begin(); it != f.end(); it++) {
        f[it->X] = s++;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
    }
    sort(a, a+n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll v = f[a[i].Y];
        modify(0, v, 1);
        modify(1, v, a[i].Y);
        ll q = query(1, 0, v);
        ll qq = query(0, 0, v);
        sum += a[i].Y * qq - q;
    }
    cout << sum << "\n";
    return 0;
}