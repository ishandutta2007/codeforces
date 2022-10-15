#include <bits/stdc++.h>
template<typename T>
struct SegmentTree {
    int N;
    std::vector<T> st;
    SegmentTree(int N) : N(N), st(2 * N) {}
    template<typename Iterator>
    SegmentTree(Iterator first, Iterator last) : SegmentTree(last - first) {
        std::copy(first, last, st.begin() + N);
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
        static std::vector<int> left, right;
        for (int l = a + N, r = b + N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left.push_back(l++);
            if (r & 1) right.push_back(--r);
        }
        left.insert(left.end(), right.rbegin(), right.rend());
        right.clear();
        T prefix = T();
        int res = b;
        for (auto p : left) {
            T nprefix = prefix + st[p];
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
struct SubarrayMin {
    T sum, pref, suff, min;
    int cnt = 0;
    SubarrayMin() : sum(0), pref(0), suff(0), min(0), cnt(0) {}
    SubarrayMin(T x) : sum(x), pref(x), suff(x), min(0), cnt(1) {}
    SubarrayMin operator+(SubarrayMin rhs) const {
        SubarrayMin res;
        res.sum = sum + rhs.sum;
        res.pref = std::min(pref, sum + rhs.pref);
        res.suff = std::min(rhs.suff, rhs.sum + suff);
        res.cnt = cnt + rhs.cnt;
        res.min = std::min(min, rhs.min);
        if (cnt && rhs.cnt) {
            res.min = std::min(res.min, suff + rhs.pref);
        }
        return res;
    }
};
template<typename T>
struct Max {
    T max;
    Max() : max(std::numeric_limits<T>::min()) {}
    Max(T x) : max(x) {}
    Max operator+(const Max& rhs) const {
        return std::max(max, rhs.max);
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int64_t> a(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
        }
        int64_t x;
        std::cin >> x;
        for (int i = 0; i < N; ++i) {
            a[i] -= x;
        }
        SegmentTree<SubarrayMin<int64_t>> st(a.begin(), a.end());
        SegmentTree<Max<int>> dp(N + 1);
        dp.modify(N, N);
        int last = 0, ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            dp.modify(i, last + i);
            int r = st.find_right(i, N, [](auto v) { return v.min == 0; });
            last = dp.query(i, r + 1).max - i;
            ans = std::max(ans, last);
        }
        std::cout << ans << '\n';
    }
    exit(0);
}