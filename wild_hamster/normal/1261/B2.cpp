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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 10000007
#define MOD 998244353
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
pii a[200500];
vector<pii> f;

struct SegmentTree {
    SegmentTree(ll n) : n(n), t(n * 2, 0) {}
    SegmentTree(vector<ll> x) : n(x.size()), t(n * 2, 0) {
        for (int i = 0; i < n; ++i) {
            t[i + n] = x[i];
        }
        build();
    }
    ll combine(ll a, ll b) { return a + b; }
    void build() {  // build the tree
        for (ll i = n - 1; i > 0; --i) t[i] = combine(t[i << 1], t[(i << 1) | 1]);
    }
    void modify(ll p, ll value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = combine(t[p], t[p ^ 1]);
    }
    ll query(ll l, ll r) {  // [l, r)
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = combine(res, t[l++]);
            if (r & 1) res = combine(res, t[--r]);
        }
        return res;
    }
    ll n;
    vector<ll> t;
};

ll ans[200500];
vector<pii> queries[200500];
SegmentTree seg_tree(200500);
ll b[200500];

bool cmp(pii x, pii y) {
    return mp(-x.X, x.Y) < mp(-y.X, y.Y);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
        a[i].Y = i;
    }
    sort(a, a+n, cmp);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        queries[x].push_back(mp(y, i));
    }
    for (int i = 1; i <= n; i++) {
        b[a[i-1].Y] = a[i-1].X;
        seg_tree.modify(a[i-1].Y, 1);
        for (auto curq : queries[i]) {
            ll l = 0, r = n - 1;
            ll val = curq.X;
            while (l < r) {
                ll mid = (l + r) / 2;
                if (seg_tree.query(0, mid + 1) >= val) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            //cout << i << " " << val << " " << l << endl;
            ans[curq.Y] = b[l];
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}