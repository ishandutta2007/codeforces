
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll t[2005000];
pii a[200500], b[200500];
pair<ll, pii> c[200500];
ll d[1000500];
ll p;
int h;

void apply(int p, ll value) {
    t[p] += value;
    if (p < n) d[p] += value;
}

void build(int p) {
    while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
}

void push(int p) {
    for (int s = h; s > 0; --s) {
        int i = p >> s;
        if (d[i] != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = 0;
        }
    }
}

void inc(int l, int r, ll value) {
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}

ll query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r - 1);
    ll res = -2e18;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(t[--r], res);
    }
    return res;
}

bool cmp(pii x, pii y) {
    return x.Y < y.Y;
}
bool cmp2(pair<ll, pii> x, pair<ll, pii> y) {
    return x.Y.X < y.Y.X;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    n = 1000000 + 5;
    h = 20;
    cin >> x >> y >> p;
    for (int i = 0; i < x; i++) {
        cin >> a[i].X >> a[i].Y;
    }
    for (int i = 0; i < y; i++) {
        cin >> b[i].X >> b[i].Y;
    }
    sort(a, a + x, cmp);
    sort(b, b + y);
    ll cur = 0;
    for (int i = 0; i < x; i++) {
        if (a[i].X > cur) {
            inc(cur, a[i].X, -a[i].Y);
            cur = a[i].X;
        }
    }
    inc(cur, n, -(ll)1e+18);
    for (int i = 0; i < p; i++) {
        cin >> c[i].X >> c[i].Y.X >> c[i].Y.Y;
    }
    sort(c, c+p, cmp2);
    ll pos = 0;
    ll ans = -(ll)1e+18;
    for (int i = 0; i < y; i++) {
        while (pos < p && c[pos].Y.X < b[i].X) {
            inc(c[pos].X, n, c[pos].Y.Y);
            pos++;
        }
        ans = max(ans, -b[i].Y + query(0, n));
    }
    cout << ans << "\n";
    return 0;
}