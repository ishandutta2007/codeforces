#include <bits/stdc++.h>
using namespace std;
template<typename F>
struct LazyST {
    using T = typename F::Type;
    int n;
    vector<typename F::Node> st;
    vector<F> lazy;
    int left(int p) const { return 2 * p + 1; }
    int right(int p) const { return 2 * p + 2; }
    void push(int p) {
        lazy[p].apply(st[p]);
        if (st[p].l != st[p].r) {
            lazy[left(p)].compose(lazy[p]);
            lazy[right(p)].compose(lazy[p]);
        }
        lazy[p] = F();
    }
    void update(int p, int ql, int qr, F op) {
        push(p);
        if (st[p].r < ql || qr < st[p].l || op.can_break(st[p])) return;
        else if (ql <= st[p].l && st[p].r <= qr && op.can_apply(st[p])) {
            lazy[p] = op;
            push(p);
        }
        else {
            update(left(p), ql, qr, op);
            update(right(p), ql, qr, op);
            st[p].value = F::op(st[left(p)].value, st[right(p)].value);
        }
    }
    T query(int p, int ql, int qr) {
        if (st[p].r < ql || qr < st[p].l) return F::Id;
        push(p);
        if (ql <= st[p].l && st[p].r <= qr) return st[p].value;
        return F::op(query(left(p), ql, qr), query(right(p), ql, qr));
    }
    template<typename C>
    void build(int p, int l, int r, const C& a) {
        st[p].l = l, st[p].r = r;
        if (l == r) st[p].value = a[l];
        else {
            int m = l + (r - l) / 2;
            build(left(p), l, m, a), build(right(p), m + 1, r, a);
            st[p].value = F::op(st[left(p)].value, st[right(p)].value);
        }
    }
    void partition(vector<int>& q, int p, int ql, int qr) {
        if (st[p].r < ql || qr < st[p].l) return;
        if (ql <= st[p].l && st[p].r <= qr) return (void)q.push_back(p);
        partition(q, left(p), ql, qr);
        partition(q, right(p), ql, qr);
    }
    template<typename S, typename Cmp>
    int binary_search(int p, T prefix, S value, Cmp&& cmp) {
        if (st[p].l == st[p].r) return st[p].l + cmp(F::op(prefix, st[p].value), value);
        push(left(p));
        T x = F::op(prefix, st[left(p)].value);
        if (cmp(x, value)) {
            push(right(p));
            return binary_search(right(p), x, value, cmp);
        }
        else {
            return binary_search(left(p), prefix, value, cmp);
        }
    }
    template<typename C>
    LazyST(const C& a) : n((int)size(a)), st(4 * n + 1), lazy(4 * n + 1) {
        build(0, 0, n - 1, a);
    }
    void update(int l, int r, F op) {
        update(0, l, r, op);
    }
    T query(int l, int r) {
        return query(0, l, r);
    }
    int lower_bound(T value) {
        return binary_search(0, F::Id, value, less<T>());
    }
    int lower_bound(int l, int r, T value) {
        return lower_bound(l, r, value, less<T>());
    }
    template<typename S, typename Cmp>
    int lower_bound(int l, int r, S value, Cmp&& cmp) {
        static vector<int> q;
        partition(q, 0, l, r);
        int res = r + 1;
        T prefix = F::Id;
        for (auto p : q) {
            push(p);
            T x = F::op(prefix, st[p].value);
            if (cmp(x, value)) prefix = x;
            else {
                res = binary_search(p, prefix, value, cmp);
                break;
            }
        }
        q.clear();
        return res;
    }
};
template<typename T>
struct F {
    using Type = T;
    inline static const Type Id = numeric_limits<T>::min();
    static Type op(Type x, Type y) {
        return max(x, y);
    }
    struct Node {
        Type value = Id;
        int l, r;
    };
    T chmin;
    F(T chmin = numeric_limits<T>::max()) : chmin(chmin) {}
    bool can_break(const Node& p) const { return false; }
    bool can_apply(const Node& p) const { return true; }
    void apply(Node& p) const {
        p.value = min(p.value, chmin);
    }
    void compose(F op) {
        chmin = min(chmin, op.chmin);
    }
};
const int inf = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m, inf);
    LazyST<F<int>> st(a);
    vector<int> l(n), r(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i] >> w[i];
        --l[i], --r[i];
    }
    vector<int> I(n);
    iota(begin(I), end(I), 0);
    sort(begin(I), end(I), [&](int i1, int i2) { return w[i1] > w[i2]; });
    int ans = inf;
    for (auto i : I) {
        st.update(l[i], r[i] - 1, w[i]);
        ans = min(ans, st.query(0, m - 2) - w[i]);
    }
    cout << ans << '\n';
    exit(0);
}