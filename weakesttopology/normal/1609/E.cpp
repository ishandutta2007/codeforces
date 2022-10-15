#include <bits/stdc++.h>
constexpr int K = 3;
struct Monoid {
    int dp[K][K];
    Monoid() {
        memset(dp, 0, sizeof(dp));
    }
    Monoid(int c) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= c; ++i) {
            dp[i][c] = 1;
        }
    }
    Monoid operator+(Monoid rhs) const {
        Monoid res;
        memset(res.dp, 0x3f, sizeof(res.dp));
        for (int i = 0; i < K; ++i) {
            for (int j = i; j < K; ++j) {
                for (int k = j; k < K; ++k) {
                    res.dp[i][k] = std::min(res.dp[i][k], dp[i][j] + rhs.dp[j][k]);
                }
            }
        }
        return res;
    }
};
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
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, Q;
    std::string s;
    std::cin >> N >> Q >> s;
    std::vector<Monoid> init(N);
    for (int i = 0; i < N; ++i) {
        init[i] = Monoid(s[i] - 'a');
    }
    SegmentTree<Monoid> st(init.begin(), init.end());
    for (int q = 0; q < Q; ++q) {
        int i;
        char c;
        std::cin >> i >> c;
        --i;
        st.modify(i, Monoid(c - 'a'));
        int ans = std::numeric_limits<int>::max();
        auto info = st.query(0, N);
        for (int k = 0; k < K; ++k) {
            ans = std::min(ans, info.dp[0][k]);
        }
        std::cout << ans << '\n';
    }
    exit(0);
}