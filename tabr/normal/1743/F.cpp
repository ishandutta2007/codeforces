#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()

using ll = long long;

const ll mod = 998244353;

template<class T>
using vec = vector<T>;

using pii = pair<int, int>;

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < n)x++;
    return x;
}

struct segtree {
    using S = array<array<ll, 2>, 2>;

    S op(S a, S b) {
        S c = {};
        rep(i, 2) {
            rep(j, 2) {
                rep(k, 2) {
                    c[i][j] += b[i][k] * a[k][j];
                }
                c[i][j] %= mod;
            }
        }
        return c;
    }

    S e() {
        return S{array < ll,
                 2 > {1, 0},
                 array < ll,
                 2 > {0, 1}};
    }

    int n, size, log;
    vector <S> d;

    segtree(int nn) {
        n = nn;
        log = ceil_pow2(n);
        size = 1 << log;
        d = vector<S>(2 * size, e());
    }

    void set(int p, S x) {
        p += size;
        d[p] = x;
        while (p > 1) {
            p >>= 1;
            d[p] = op(d[2 * p], d[2 * p + 1]);
        }
    }

    S prod(int l, int r) {
        S sml = e(), smr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    const int m = 3e5 + 10;
    vec<vec<int>> e(m);
    int l0, r0;
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        if (i == 0) {
            l0 = l;
            r0 = r;
        }
        e[l].emplace_back(i);
        e[r].emplace_back(~i);
    }
    segtree seg(n);
    segtree::S m0 = {}, m1 = {};
    m0[0] = {3, 1};
    m0[1] = {0, 2};
    m1[0] = {1, 1};
    m1[1] = {2, 2};
    rep(i, n) {
        seg.set(i, m0);
    }
    ll ans = 0;
    rep(i, m) {
        for (auto x: e[i]) {
            if (x >= 0) {
                seg.set(x, m1);
            }
        }
        auto t = seg.prod(1, n);
        if (l0 <= i && i <= r0) {
            ans += t[1][1];
        } else {
            ans += t[1][0];
        }
        ans %= mod;
//        if (i < 10)cerr << t[0][0] << " " << t[0][1] << endl;
        for (auto x: e[i]) {
            if (x < 0) {
                seg.set(~x, m0);
            }
        }
    }
    cout << ans << endl;
    return 0;
}