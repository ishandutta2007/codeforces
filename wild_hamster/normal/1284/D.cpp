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
#define MAXN 300500
#define OFF 200001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
struct hyu {
    ll a;
    ll b;
    ll c;
    ll d;
};
hyu e[300500];
vector<pii> f;
bool cmp(hyu x, hyu y) {
    return std::tie(x.a, x.b, x.c, x.d) < std::tie(y.a, y.b, y.c, y.d);
}

ll t1[2 * MAXN], t2[2*MAXN];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t1[i] = max(t1[i<<1], t1[i<<1|1]);
    for (int i = n - 1; i > 0; --i) t2[i] = min(t2[i<<1], t2[i<<1|1]);
}

ll query_max(int l, int r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t1[l++]);
        if (r&1) res = max(res, t1[--r]);
    }
    return res;
}

ll query_min(int l, int r) {  // sum on interval [l, r)
    ll res = 5LL + (ll)1e+9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, t2[l++]);
        if (r&1) res = min(res, t2[--r]);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> e[i].a >> e[i].b >> e[i].c >> e[i].d;
    }

    sort(e, e+n, cmp);
    for (int i = 0; i < 3*n; i++) {
        t1[i] = 0;
        t2[i] = 5LL + (ll)1e+9;
    }
    for (int i = 0; i < n; i++) {
        t1[n+i] = e[i].c;
        t2[n+i] = e[i].d;
    }

    build();
    f.clear();
    for (int i = 0; i < n; i++) {
        f.push_back(mp(e[i].a, e[i].b));
    }
    for (int i = 0; i < n; i++) {
        ll pos = upper_bound(f.begin(), f.end(), mp(e[i].b + 1, -1LL)) - f.begin();
        if (query_max(i, pos) > e[i].d || query_min(i, pos) < e[i].c) {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        swap(e[i].a, e[i].c);
        swap(e[i].b, e[i].d);
    }

    sort(e, e+n, cmp);
    for (int i = 0; i < 3*n; i++) {
        t1[i] = 0;
        t2[i] = 5LL + (ll)1e+9;
    }
    for (int i = 0; i < n; i++) {
        t1[n+i] = e[i].c;
        t2[n+i] = e[i].d;
    }
    build();
    f.clear();
    for (int i = 0; i < n; i++) {
        f.push_back(mp(e[i].a, e[i].b));
    }
    for (int i = 0; i < n; i++) {
        ll pos = upper_bound(f.begin(), f.end(), mp(e[i].b + 1, -1LL)) - f.begin();
        if (query_max(i, pos) > e[i].d || query_min(i, pos) < e[i].c) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;

}