#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>


using namespace std;
using namespace __gnu_pbds; // policy-based

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

vector<int> sort_cyclic_shifts(const string& s) {
    int n = (int)size(s);
    vector<int> p(n), inv(n), tmp(n), cnt(n);
    iota(all(p), 0);
    sort(all(p), [&s](int i, int j){ return s[i] < s[j]; });
    inv[p[0]] = 0;
    for (int i = 1; i < n; ++i) {
        inv[p[i]] = inv[p[i - 1]] + (s[p[i]] != s[p[i - 1]] ? 1 : 0);
    }
    for (int shift = 1; shift < n; shift *= 2) {
        fill(all(cnt), 0);
        for (int i = 0; i < n; ++i) {
            tmp[n - 1 - i] = (p[i] + n - shift) % n;
            cnt[inv[p[i]]] += 1;
        }
        partial_sum(all(cnt), begin(cnt));
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

template<typename T>
struct M1 {
    using Type = T;
    inline const static T Id = 0;
    static T op(const T& x, const T& y) { return x + y; }
};

template<typename Monoid>
struct PersistentST {
    using M = Monoid;
    using T = typename Monoid::Type;
    struct Node {
        T value = M::Id;
        int left = -1, right = -1, root;
        Node (int root) : root(root) {}
    };
    int n;
    deque<Node> st;
    int num_nodes;

    int create(int rt = -1) {
        if (rt == -1) rt = num_nodes;
        st.emplace_back(rt);
        return num_nodes++;
    }
    inline T get(int p) { return p == -1 ? M::Id : st[p].value; }

    // p must be a reference!
    void modify(int rt, int &p, int l, int r, int pos, T value) {
        if (p == -1) p = create(rt);
        else if (st[p].root != rt) {
            int temp = p;
            p = create();
            st[p] = st[temp], st[p].root = rt;
        }
        if (l == r) st[p].value = value;
        else {
            int m = l + (r - l) / 2;
            pos <= m ? modify(rt, st[p].left, l, m, pos, value) : modify(rt, st[p].right, m + 1, r, pos, value);
            st[p].value = M::op(get(st[p].left), get(st[p].right));
        }
    }
    T query(int p, int l, int r, int ql, int qr) {
        if (p == -1 || r < ql || qr < l) return M::Id;
        if (ql <= l && r <= qr) return st[p].value;
        int m = l + (r - l) / 2;
        T resl = query(st[p].left, l, m, ql, qr);
        T resr = query(st[p].right, m + 1, r, ql, qr);
        return M::op(resl, resr);
    }
    int merge(int rt, int p, int q) {
        if (p == -1) return q;
        if (q == -1) return p;
        int r = p;
        st[r].value = M::op(get(p), get(q));
        st[r].left = merge(rt, st[p].left, st[q].left);
        st[r].right = merge(rt, st[p].right, st[q].right);
        return r;
    }
    void build(int rt, int p, int l, int r, const vector<T>& a) {
        if (l == r) st[p].value = a[l];
        else {
            int m = l + (r - l) / 2;
            st[p].left = create(rt), st[p].right = create(rt);
            build(rt, st[p].left, l, m, a), build(rt, st[p].right, m + 1, r, a);
            st[p].value = M::op(get(st[p].left), get(st[p].right));
        }
    }
    PersistentST(int n) : n(n), num_nodes(0) { create(); }
    int build(const vector<T>& a) {
        assert(size(a) == n);
        int rt = create();
        build(rt, rt, 0, n - 1, a);
        return rt;
    }
    int duplicate(int root) {
        int rt = create();
        st[rt] = st[root];
        st[rt].root = rt;
        return rt;
    }
    // doesn't make sense with uncommutative operations, versions are not modified
    // O(size of tree overlap)
    int merge(int root1, int root2) {
        return merge(num_nodes, root1, root2);
    }
    // modifies version in place
    void modify(int root, int pos, T value) {
        modify(root, root, 0, n - 1, pos, value);
    }
    T query(int root, int l, int r) {
        return query(root, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    string t;
    vector<string> s(n);
    vector<int> b(n), len(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        b[i] = (int)size(t);
        len[i] = (int)size(s[i]);
        t += s[i] + '#';
    }
    int T = (int)size(t);

    SuffixArray sa(t);
    sa.build_lcp();
    sa.build_suffix_tree();

    auto& st = sa.st;
    int m = (int)size(st);

    vector<int> p(m), largest(T);
    iota(all(p), 0);

    PersistentST<M1<int>> pst(T);
    vector<int> rt(m, - 1);

    for (int u = 1; u < m; ++u) {
        if (st[u].idx + st[u].len == T) {
            largest[st[u].idx] = u;
            rt[u] = pst.create();
            pst.modify(rt[u], st[u].idx, 1);
        }
    }
    auto find = [&](auto& self, int u, int len) -> int {
        u = p[u];
        int lnk = st[u].link;
        return st[lnk].len >= len ? p[u] = self(self, lnk, len) : u;
    };

    vector<int> vtx(n), I(n);
    iota(all(I), 0);
    sort(all(I), [&](int i, int j){ return len[i] > len[j]; });
    for (auto i : I) vtx[i] = find(find, largest[b[i]], len[i]);

    vector<int> l(q), r(q);
    vector<vector<int>> queries(m);
    for (int z = 0; z < q; ++z) {
        int k;
        cin >> l[z] >> r[z] >> k;
        --l[z], --r[z], --k;
        queries[vtx[k]].push_back(z);
    }

    vector<int> V(m - 1);
    iota(all(V), 1);
    sort(all(V), [&](int u, int v){ return st[u].len > st[v].len; });

    vector<int> ans(q);
    for (auto u : V) {
        for (auto z : queries[u]) {
            ans[z] = pst.query(rt[u], b[l[z]], b[r[z]] + len[r[z]] - 1);
        }
        int p = st[u].link;
        rt[p] = pst.merge(rt[p], rt[u]);
    }

    for (int z = 0; z < q; ++z) {
        cout << ans[z] << endl;
    }

    exit(0);
}