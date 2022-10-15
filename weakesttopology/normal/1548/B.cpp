#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct SegmentTree {
    int n;
    vector<T> st;
    SegmentTree(int n) : n(n), st(2 * n) {}
    template<typename Iterator>
    SegmentTree(Iterator first, Iterator last) : SegmentTree(int(last - first)) {
        copy(first, last, begin(st) + n);
        for (int p = n - 1; p > 0; --p) {
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
    }
    void modify(int p, T value) {
        for (st[p += n] = value; p > 1; p >>= 1) {
            st[p >> 1] = st[p & ~1] + st[p | 1];
        }
    }
    T query(int l, int r) const {
        T resl = T(), resr = T();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = resl + st[l++];
            if (r & 1) resr = st[--r] + resr;
        }
        return resl + resr;
    }
    template<typename Pred>
    int binary_search(int p, T prefix, Pred&& pred) const {
        while (p < n) {
            int l = p << 1, r = p << 1 | 1;
            T nprefix = prefix + st[l];
            if (pred(nprefix)) {
                prefix = nprefix;
                p = r;
            } else {
                p = l;
            }
        }
        return p - n;
    }
    int lower_bound(int a, int b, T value) const {
        return find_right(a, b, [value](T x) { return x < value; });
    }
    // first i in [a, b) with pred(query(a, i + 1)) == false
    // returns b if no such i exists
    template<typename Pred>
    int find_right(int a, int b, Pred&& pred) {
        static vector<int> left, right;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left.push_back(l++);
            if (r & 1) right.push_back(--r);
        }
        left.insert(end(left), rbegin(right), rend(right));
        right.clear();
        T prefix = T();
        int res = b;
        for (auto p : left) {
            T nprefix = prefix + st[p].value;
            if (pred(nprefix)) {
                prefix = nprefix;
            } else {
                res = binary_search(p, prefix, pred);
                break;
            }
        }
        left.clear();
        return res;
    }
};
template<typename T>
struct GcdMonoid {
    T value;
    GcdMonoid(T value = 0) : value(value) {}
    GcdMonoid operator+(GcdMonoid rhs) const {
        return GcdMonoid(gcd(value, rhs.value));
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), d(n - 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i > 0) {
                d[i - 1] = a[i] - a[i - 1];
            }
        }
        SegmentTree<GcdMonoid<long long>> st(begin(d), end(d));
        int ans = 1;
        for (int i = 0; i < n - 1; ++i) {
            int r = st.find_right(i, n - 1, [](auto x) { return x.value != 1; });
            ans = max(ans, r - i + 1);
        }
        cout << ans << '\n';
    }
    exit(0);
}