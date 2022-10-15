#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> sort_cyclic_shifts(const string& s) {
    int n = (int)size(s);
    vector<int> p(n), inv(n), tmp(n), cnt(n);
    iota(begin(p), end(p), 0);
    sort(begin(p), end(p), [&s](int i, int j){ return s[i] < s[j]; });
    inv[p[0]] = 0;
    for (int i = 1; i < n; ++i) {
        inv[p[i]] = inv[p[i - 1]] + (s[p[i]] != s[p[i - 1]] ? 1 : 0);
    }
    for (int shift = 1; shift < n; shift *= 2) {
        fill(begin(cnt), end(cnt), 0);
        for (int i = 0; i < n; ++i) {
            tmp[n - 1 - i] = (p[i] + n - shift) % n;
            cnt[inv[p[i]]] += 1;
        }
        partial_sum(begin(cnt), end(cnt), begin(cnt));
        for (auto i : tmp) p[--cnt[inv[i]]] = i;
        auto key = [&](int i) { return pair(inv[i], inv[(i + shift) % n]); };
        tmp[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            tmp[p[i]] = tmp[p[i - 1]] + (key(p[i - 1]) != key(p[i]) ? 1 : 0);
        }
        swap(tmp, inv);
    }
    return p;
}
struct SuffixArray {
    const string s;
    int n;
    vector<int> p, pos, lcp;
    SuffixArray(const string& s_) : s(s_ + char(0)), n((int)size(s)), pos(n, 0) {
        p = sort_cyclic_shifts(s);
        for (int i = 0; i < n; ++i) pos[p[i]] = i;
        build_lcp();
        build_suffix_tree();
    }
    void build_lcp() {
        lcp.assign(n, 0);
        for (int i = 0, k = 0; i < n - 1; ++i, k = max(0, k - 1)) {
            if (pos[i] == n - 1) {
                k = 0;
                continue;
            }
            for (int j = p[pos[i] + 1]; max(i, j) + k < n && s[i + k] == s[j + k]; ++k);
            lcp[pos[i]] = k;
        }
    }
    template<typename RMQ> int lcp_query(int i, int j, const RMQ& rmq) const {
        if (i == j) return (int)size(pos) - i;
        if (pos[i] > pos[j]) swap(i, j);
        return rmq.query(pos[i], pos[j] - 1);
    }
    // substring comparison
    template<typename RMQ> bool cmp(array<int, 2> S, array<int, 2> T, const RMQ& rmq) const {
        int lenS = S[1] - S[0] + 1, lenT = T[1] - T[0] + 1;
        int L = lcp_query(S[0], T[0], rmq);
        return L < min(lenS, lenT) ? s[S[0] + L] < s[T[0] + L] : lenS < lenT;
    }
    struct Node {
        int link, len, idx;
    };
    vector<Node> st;
    int create(int len, int idx) {
        st.push_back({-1 , len, idx});
        return (int)size(st) - 1;
    }
    void build_suffix_tree() {
        stack<int> stk;
        stk.push(create(0, -1));
        for (int i = 1; i < n; ++i) {
            for (auto len : {n - 1 - p[i], lcp[i]}) {
                int l = p[i];
                while (st[stk.top()].len > len) {
                    int v = stk.top();
                    stk.pop();
                    l = st[v].idx;
                    if (len > st[stk.top()].len) stk.push(create(len, l));
                    st[v].link = stk.top();
                }
                if (len > st[stk.top()].len) stk.push(create(len, l));
            }
        }
    }
};
struct Data {
    int sum = 0, low = 1e7, cntlow = 0;
    Data() {}
    Data(int x) : sum(x), low(x), cntlow(1) {}
    Data operator+(Data rhs) const {
        Data res;
        res.sum = sum + rhs.sum;
        res.low = min(low, sum + rhs.low);
        if (low == res.low) res.cntlow += cntlow;
        if (sum + rhs.low == res.low) res.cntlow += rhs.cntlow;
        return res;
    }
    bool operator<(Data rhs) const { return low > rhs.low; }
};
template<typename T>
struct M1 {
    using Type = T;
    inline const static Type Id = Type();
    static Type op(Type x, Type y) { return x + y; }
};
template<typename Monoid>
struct SegmentTree {
    using M = Monoid;
    using T = typename Monoid::Type;
    int n;
    vector<T> st;
    template<typename S, typename Cmp>
    int binary_search(int p, T prefix, S value, Cmp&& cmp) {
        while (p < n) if (T x = M::op(prefix, st[p <<= 1]); cmp(x, value))
            prefix = x, p |= 1;
        return p - n + cmp(M::op(prefix, st[p]), value);
    }
    SegmentTree(int n) : n(n), st(2 * n, M::Id) { }
    SegmentTree(const vector<T>& a) : SegmentTree((int)size(a)) {
        for (int i = 0; i < n; ++i) st[n + i] = a[i];
        for (int i = n - 1; i > 0; --i)
            st[i] = M::op(st[i << 1], st[i << 1 | 1]);
    }
    void modify(int p, T value) {
        for (st[p += n] = value; p > 1; p >>= 1)
            st[p >> 1] = M::op(st[p & ~1], st[p | 1]);
    }
    T query(int l, int r) {
        T resl = M::Id, resr = M::Id;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = M::op(resl, st[l++]);
            if (r & 1) resr = M::op(st[--r], resr);
        }
        return M::op(resl, resr);
    }
    int lower_bound(T value) { return lower_bound(0, n - 1, value); }
    // first x in [a, b] with cmp(query(a, x), value) == false
    // returns b + 1 if no such x exists
    template<typename S, typename Cmp>
    int lower_bound(int a, int b, S value, Cmp&& cmp) {
        static vector<int> left, right;
        for (int l = a + n, r = b + n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left.push_back(l++);
            if (r & 1) right.push_back(--r);
        }
        left.insert(end(left), rbegin(right), rend(right));
        right.clear();
        T prefix = M::Id;
        for (size_t i = 0; i < size(left); ++i) {
            int p = left[i];
            if (T x = M::op(prefix, st[p]); cmp(x, value)) prefix = x;
            else {
                left.clear();
                return binary_search(p, prefix, value, cmp);
            }
        }
        left.clear();
        return b + 1;
    }
    template<typename S>
    int lower_bound(int a, int b, S value) {
        return lower_bound(a, b, value, less<T>());
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<Data> a(n);
    for (int i = 0; i < n; ++i) a[i] = Data(s[i] == '(' ? +1 : -1);
    SegmentTree<M1<Data>> seg(a);
    SuffixArray sa(s);
    auto& st = sa.st;
    int m = (int)size(st);
    ll ans = 0;
    for (int u = 1; u < m; ++u) {
        int i = st[u].idx, len = st[u].len, minlen = st[st[u].link].len + 1;
        auto p = seg.query(i, i + minlen - 1);
        if (p.low < 0) continue;
        if (p.sum == 0) ++ans;
        if (len == minlen) continue;
        int j = seg.lower_bound(i + minlen, i + len - 1, -p.sum - 1, [](auto q, int x){ return q.low > x; });
        if (i + minlen < j) {
            auto q = seg.query(i + minlen, j - 1);
            if (q.low == -p.sum) ans += q.cntlow;
        }
    }
    cout << ans << endl;
    exit(0);
}