#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<int K = 26, char offset = 'a'>
struct SuffixAutomaton {
    struct State {
        int link, len, minlen, idx;
        int nxt[K];
        bool clone = false;
        State(int link = -1, int len = 0) : link(link), len(len) { fill(all(nxt), -1); }
    };
    vector<State> st;

    SuffixAutomaton(const string& s) : st(1) {
        for (auto c : s) extend(c);
    }

    int last = 0, total_size = 0;
    void extend(char c) {
        int u = last, len = st[last].len + 1, ch = c - offset;
        last = (int)size(st);

        for (; u != -1 && st[u].nxt[ch] == -1; u = st[u].link) st[u].nxt[ch] = last;

        if (u == -1) {
            st.emplace_back(0, len);
        }
        else if (int v = st[u].nxt[ch]; st[u].len + 1 == st[v].len) {
            st.emplace_back(v, len);
        }
        else {
            int clone = last + 1;
            st.emplace_back(clone, len);
            st.push_back(st[v]);

            st[clone].len = st[u].len + 1, st[clone].clone = true;
            st[v].link = clone, st[v].minlen = st[clone].len + 1;

            for (int p = u; p != -1 && st[p].nxt[ch] == v; p = st[p].link) st[p].nxt[ch] = clone;
        }

        st[last].minlen = st[st[last].link].len + 1;
        st[last].idx = total_size++;
    }
    int go(int u, char c) const { return st[u].nxt[c - offset]; }
    // sorts largest to smallest
    vector<int> radix_sort() const {
        int m = (int)size(st);
        vector<int> V(m), cnt(total_size + 1, 0);
        for (int u = 0; u < m; ++u) cnt[st[u].len] += 1;
        for (int x = total_size - 1; x >= 0; --x) cnt[x] += cnt[x + 1];
        for (int u = 0; u < m; ++u) V[--cnt[st[u].len]] = u;
        return V;
    }
};

template<typename T>
struct M1 {
    using Type = T;
    inline const static T Id = 0;
    static T op(const T& x, const T& y) { return x + y; }
};

template<typename Monoid>
class PersistentST {
private:
    using M = Monoid;
    using T = typename Monoid::Type;
    struct Node {
        T value = M::Id;
        int left = -1, right = -1, root;
        Node (int root) : root(root) {}
    };
    const int n;
    deque<Node> st;
    int num_nodes;

    int create(int rt = -1) {
        if (rt == -1) rt = num_nodes;
        st.emplace_back(rt);
        return num_nodes++;
    }
    inline T get(int p) { return p == -1 ? M::Id : st[p].value; }

    void modify(int rt, int& p, int l, int r, int pos, T value) {
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
        int r = create(rt);
        st[r].value = M::op(get(p), get(q));
        st[r].left = merge(rt, st[p].left, st[q].left);
        st[r].right = merge(rt, st[p].right, st[q].right);
        return r;
    }
    void build(int rt, int p, int l, int r, const vector<T>& a) {
        if (l == r) st[p].value = a[l];
        else {
            int m = l + (r - l) / 2;
            left[p] = create(rt), right[p] = create(rt);
            build(rt, left[p], l, m, a), build(rt, right[p], m + 1, r, a);
            st[p] = M::op(get(st[p].left), get(st[p].right));
        }
    }
public:
    PersistentST(int n) : n(n), num_nodes(0) { create(); }
    int build(const vector<T>& a) {
        assert(size(a) == n);
        int rt = create(num_nodes);
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
    // O(size of overlap)
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

    int n;
    string s;
    cin >> n >> s;

    SuffixAutomaton aut(s);
    const auto& st = aut.st;
    int m = (int)size(st);

    auto V = aut.radix_sort();
    vector<int> rt(m, -1);

    PersistentST<M1<int>> seg(n);

    for (int i = 0, u = 0; i < n; ++i) {
        u = aut.go(u, s[i]);
        rt[u] = seg.duplicate(0);
        seg.modify(rt[u], i, 1);
    }
    for (auto u : V) {
        int p = st[u].link;
        if (p == -1) continue;
        rt[p] = seg.merge(rt[p], rt[u]);
    }

    vector<int> dp(m, 0), from(m, 0);
    int res = 0;

    reverse(all(V));
    for (auto u : V) {
        if (st[u].link == -1) continue;
        int v = from[st[u].link];

        if (v == 0 || seg.query(rt[v], st[u].idx - st[u].len + st[v].len, st[u].idx - 1) > 0) {
            dp[u] = dp[v] + 1, from[u] = u;
        }
        else {
            dp[u] = dp[v], from[u] = v;
        }
        res = max(res, dp[u]);
    }

    cout << res << endl;
 
    exit(0);
}