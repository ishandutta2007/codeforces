#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

struct SegmentTree {
    vector<ll> t;
    int n;

    SegmentTree(int n) : t(2*n, numeric_limits<ll>::max()), n(n) { }

    void update(int i, ll x) {
        for (ckmin(t[i += n], x); i != 1; i >>= 1) t[i >> 1] = min(t[i], t[i^1]);
    }

    ll get_min(int l, int r) {
        ll res = numeric_limits<ll>::max();
        for (l += n, r += n - 1; l <= r; l >>= 1, r >>= 1) {
            if ((l&1) == 1) res = min(res, t[l++]);
            if ((r&1) == 0) res = min(res, t[r--]);
        }
        return res;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> x(n), w(n), l(q), r(q), p(q), st;
    vector<ll> ans(q);
    vector<pi> good_pairs;

    for (int i = 0; i < n; ++i) cin >> x[i] >> w[i];
    for (int i = 0; i < q; ++i) cin >> l[i] >> r[i], --l[i];
    SegmentTree sgt(n);

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && w[st.back()] >= w[i]) {
            good_pairs.emplace_back(st.back(), i);
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = n; i--; ) {
        while (!st.empty() && w[st.back()] >= w[i]) {
            good_pairs.emplace_back(i, st.back());
            st.pop_back();
        }
        st.push_back(i);
    }

    for (auto [x, y] : good_pairs) assert(x < y);

    sort(good_pairs.begin(), good_pairs.end(), [&] (pi a, pi b) { return a.S < b.S; });
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&] (int i, int j) { return r[i] < r[j]; });

    int ptr = 0;
    for (int i : p) {
        while (ptr < good_pairs.size() && good_pairs[ptr].S < r[i]) {
            const auto [s, t] = good_pairs[ptr++];
            sgt.update(s, (ll) (x[t] - x[s]) * (w[s] + w[t]));
        }

        ans[i] = sgt.get_min(l[i], r[i]);
    }

    for (ll x : ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    // cin >> t;
    while (t--) solve();
}