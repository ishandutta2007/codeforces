#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct SegmentTree {
    int N;
    vector<T> st;
    SegmentTree(int N) : N(N), st(2 * N) {}
    template<typename Iterator>
    SegmentTree(Iterator first, Iterator last) : SegmentTree(int(last - first)) {
        copy(first, last, st.begin() + N);
        for (int p = N - 1; p > 0; --p) {
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
    }
    void modify(int p, T value) {
        for (st[p += N] = value; p > 1; p >>= 1) {
            st[p >> 1] = st[p & ~1] + st[p | 1];
        }
    }
    T query(int l, int r) const {
        T resl = T(), resr = T();
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = resl + st[l++];
            if (r & 1) resr = st[--r] + resr;
        }
        return resl + resr;
    }
    template<typename Pred>
    int binary_search(int p, T prefix, Pred&& pred) const {
        while (p < N) {
            int l = p << 1, r = p << 1 | 1;
            T nprefix = prefix + st[l];
            if (pred(nprefix)) {
                prefix = nprefix;
                p = r;
            } else {
                p = l;
            }
        }
        return p - N;
    }
    int lower_bound(int a, int b, T value) const {
        return find_right(a, b, [value](T x) { return x < value; });
    }
    // first i in [a, b) with pred(query(a, i + 1)) == false (b if no such i exists)
    template<typename Pred>
    int find_right(int a, int b, Pred&& pred) {
        static vector<int> left, right;
        for (int l = a + N, r = b + N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left.push_back(l++);
            if (r & 1) right.push_back(--r);
        }
        left.insert(left.end(), right.rbegin(), right.rend());
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
struct PrefixMonoid {
    T sum, prefmin, prefmax;
    PrefixMonoid(T value = 0) : sum(value), prefmin(min<T>(0, value)), prefmax(max<T>(0, value)) {}
    PrefixMonoid operator+(const PrefixMonoid& rhs) const {
        PrefixMonoid res;
        res.sum = sum + rhs.sum;
        res.prefmin = min(prefmin, sum + rhs.prefmin);
        res.prefmax = max(prefmax, sum + rhs.prefmax);
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        a[i] -= b;
    }
    SegmentTree<PrefixMonoid<long long>> st(a.begin(), a.end());
    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        --l;
        auto x = st.query(l, r);
        long long ans = x.sum == 0 && x.prefmax == 0 ? -x.prefmin : -1;
        cout << ans << '\n';
    }
    exit(0);
}