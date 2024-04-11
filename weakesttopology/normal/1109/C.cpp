#include <bits/stdc++.h>
using namespace std;
template<typename T, typename F>
struct LazySegmentTree {
    struct Node {
        T value = T();
        F lazy = F();
        int l, r;
    };
    int n;
    vector<Node> st;
    int left(int p) const { return 2 * p + 1; }
    int right(int p) const { return 2 * p + 2; }
    void push(int p) {
        if (st[p].l + 1 == st[p].r) return;
        for (int q : {left(p), right(p)}) {
            st[p].lazy.apply(st[q]);
            st[q].lazy.compose(st[p].lazy);
        }
        st[p].lazy = F();
    }
    void update(int p, int ql, int qr, F op) {
        if (st[p].r <= ql || qr <= st[p].l || op.can_break(st[p])) {
            return;
        } else if (ql <= st[p].l && st[p].r <= qr && op.can_apply(st[p])) {
            op.apply(st[p]);
            st[p].lazy.compose(op);
        } else {
            push(p);
            update(left(p), ql, qr, op);
            update(right(p), ql, qr, op);
            st[p].value = st[left(p)].value + st[right(p)].value;
        }
    }
    T query(int p, int ql, int qr) {
        if (st[p].r <= ql || qr <= st[p].l) {
            return T();
        } else if (ql <= st[p].l && st[p].r <= qr) {
            return st[p].value;
        } else {
            push(p);
            return query(left(p), ql, qr) + query(right(p), ql, qr);
        }
    }
    template<typename Iterator>
    void build(int p, int l, int r, Iterator first) {
        st[p].l = l, st[p].r = r;
        if (l + 1 == r) {
            st[p].value = first[l];
        } else {
            int m = l + (r - l) / 2;
            build(left(p), l, m, first), build(right(p), m, r, first);
            st[p].value = st[left(p)].value + st[right(p)].value;
        }
    }
    void partition(vector<int>& q, int p, int ql, int qr) {
        if (st[p].r <= ql || qr <= st[p].l) {
            return;
        } else if (ql <= st[p].l && st[p].r <= qr) {
            q.push_back(p);
        } else {
            push(p);
            partition(q, left(p), ql, qr);
            partition(q, right(p), ql, qr);
        }
    }
    template<typename Pred>
    int binary_search(int p, T prefix, Pred&& pred) {
        if (st[p].l + 1 == st[p].r) {
            return st[p].l;
        } else {
            push(p);
            T nprefix = prefix + st[left(p)].value;
            if (pred(nprefix)) {
                return binary_search(right(p), nprefix, pred);
            } else {
                return binary_search(left(p), prefix, pred);
            }
        }
    }
    template<typename Iterator>
    LazySegmentTree(Iterator first, Iterator last) : n(int(last - first)), st(4 * n) {
        build(0, 0, n, first);
    }
    T query(int l, int r) {
        return query(0, l, r);
    }
    void update(int l, int r, F op) {
        update(0, l, r, op);
    }
    int lower_bound(int l, int r, T target) {
        return find_right(l, r, [target](T value) { return value < target; });
    }
    // returns first i in [l, r) with pred(query(l, i + 1)) == false
    // returns r if no such i exists
    template<typename Pred>
    int find_right(int l, int r, Pred&& pred) {
        static vector<int> q;
        partition(q, 0, l, r);
        int res = r;
        T prefix = T();
        for (auto p : q) {
            T nprefix = prefix + st[p].value;
            if (pred(nprefix)) {
                prefix = nprefix;
            } else {
                res = binary_search(p, prefix, pred);
                break;
            }
        }
        q.clear();
        return res;
    }
};
template<typename T>
struct PrefixMaxMonoid {
    T sum, prefmax, len;
    PrefixMaxMonoid() : sum(0), prefmax(0), len(0) {}
    PrefixMaxMonoid(T x, T len) : sum(len * x), prefmax(max<T>(0, x) * len), len(len) {}
    PrefixMaxMonoid operator+(const PrefixMaxMonoid& rhs) const {
        PrefixMaxMonoid res;
        res.sum = sum + rhs.sum;
        res.prefmax = max(prefmax, sum + rhs.prefmax);
        res.len = len + rhs.len;
        return res;
    }
};
template<typename T>
struct RangeAssignment {
    bool Id;
    T value;
    RangeAssignment() : Id(true), value(0) {}
    RangeAssignment(T value) : Id(false), value(value) {}
    template<typename Node>
    bool can_break(const Node& p) const {
        return false;
    }
    template<typename Node>
    bool can_apply(const Node& p) const {
        return true; 
    }
    template<typename Node>
    void apply(Node& p) const {
        if (not Id) {
            p.value = PrefixMaxMonoid<T>(value, p.value.len);
        }
    }
    void compose(RangeAssignment op) {
        if (not op.Id) {
            value = op.value;
            Id = false;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Q;
    cin >> Q;
    vector<array<int, 4>> queries(Q);
    vector<int> pts;
    for (int q = 0; q < Q; ++q) {
        int &type = queries[q][0];
        cin >> type;
        if (type == 1) {
            int &t = queries[q][1], &s = queries[q][2];
            cin >> t >> s;
            pts.push_back(t);
        } else if (type == 2) {
            int &t = queries[q][1];
            cin >> t;
            pts.push_back(t);
        } else {
            int &l = queries[q][1], &r = queries[q][2], &v = queries[q][3];
            cin >> l >> r >> v;
            pts.insert(end(pts), {l, r});
        }
    }
    const int tmax = 1e9;
    pts.insert(end(pts), {0, tmax + 1});
    sort(begin(pts), end(pts));
    pts.erase(unique(begin(pts), end(pts)), end(pts));
    auto Id = [&](int x) {
        return int(lower_bound(begin(pts), end(pts), x) - begin(pts));
    };
    int N = (int)size(pts) - 1;
    using P = PrefixMaxMonoid<long long>;
    using R = RangeAssignment<long long>;
    vector<P> init(N);
    for (int i = 0; i < N; ++i) {
        init[i] = P(0, pts[i + 1] - pts[i]);
    }
    LazySegmentTree<P, R> st(begin(init), end(init));
    map<int, int> color;
    color[0] = color[N] = 0;
    cout << setprecision(10) << fixed;
    for (int q = 0; q < Q; ++q) {
        int type = queries[q][0];
        if (type == 1) {
            int t = Id(queries[q][1]), s = -queries[q][2];
            int r = color.upper_bound(t)->first;
            st.update(t, r, R(s));
            color[t] = s;
        } else if (type == 2) {
            int t = Id(queries[q][1]);
            auto iter = color.find(t);
            st.update(t, next(iter)->first, R(prev(iter)->second));
            color.erase(iter);
        } else {
            int l = Id(queries[q][1]), r = Id(queries[q][2]), v = queries[q][3];
            if (v == 0) {
                cout << pts[l] << '\n';
                continue;
            }
            l = color.lower_bound(l)->first;
            int i = st.find_right(l, r, [v](auto p) { return p.prefmax < v; });
            if (i == r) {
                cout << "-1\n";
            } else {
                int s = prev(color.upper_bound(i))->second;
                auto [sum, prefmax, len] = st.query(l, i);
                double ans = pts[i] + 1.0 * (v - sum) / s;
                cout << ans << '\n';
            }
        }
    }
    exit(0);
}