#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<int K = 26, char offset = 'a'>
struct AhoCorasick {
    struct Node {
        int nxt[K], go[K];
        bool leaf = false;
        int p = -1, link = -1, leaflink = -1;
        char pc;
        Node(int p = -1, char pc = offset - 1) : p(p), pc(pc) {
            fill(begin(nxt), end(nxt), -1), fill(begin(go), end(go), -1);
        }
    };
    vector<Node> trie;
    AhoCorasick() : trie(1) {}
    int add(const string& s) {
        int u = 0;
        for (auto c : s) {
            int v = trie[u].nxt[c - offset];
            if (v == -1) {
                v = (int)size(trie);
                trie.emplace_back(u, c);
            }
            u = trie[u].nxt[c - offset] = v;
        }
        trie[u].leaf = true, trie[u].leaflink = u;
        return u;
    }
    void remove(int u) {
        trie[u].leaf = false, trie[u].leaflink = -1;
    }
    int getlink(int v) {
        if (trie[v].link == -1) {
            if (v == 0 || trie[v].p == 0) trie[v].link = 0;
            else trie[v].link = go(getlink(trie[v].p), trie[v].pc);
        }
        return trie[v].link;
    }
    int go(int v, char c) {
        int idx = c - offset;
        if (trie[v].go[idx] == -1) {
            if (trie[v].nxt[idx] != -1) trie[v].go[idx] = trie[v].nxt[idx];
            else trie[v].go[idx] = (v == 0 ? 0 : go(getlink(v), c));
        }
        return trie[v].go[idx];
    }
    // inclusive
    int getleaf(int v) {
        int &u = trie[v].leaflink;
        if (u == -1) {
            if (v == 0 || trie[v].leaf) u = v;
            else u = getleaf(getlink(v));
        }
        if (trie[u].leaflink != u) u = getleaf(u);
        return u;
    }
    // reports all occurrences in s (in order)
    // O(size(s) + number of occurrences) amortized
    template<typename F>
    void run(const string& s, F&& report) {
        int n = (int)size(s);
        for (int i = 0, u = 0; i < n; ++i) {
            u = go(u, s[i]);
            for (int v = getleaf(u); v != 0; v = getleaf(getlink(v))) report(i, v);
        }
    }
};
template<typename T>
struct G1 {
    using Type = T;
    inline const static T Id = 0;
    static T op(const T& x, const T& y) { return x + y; }
    static T inv(const T& x) { return -x; }
    static bool cmp(const T& x, const T& y) { return x < y; }
};
int b(int p) { return p & (-p); }
template<typename Group>
struct BIT {
    using G = Group;
    using T = typename G::Type;
    int n, h;
    vector<T> ft;
    T query(int p) {
        T res = G::Id;
        for (; p; p -= b(p)) res = G::op(ft[p], res);
        return res;
    }
    BIT(int n) : n(n), h(31 - __builtin_clz(n)), ft(n + 1, G::Id) { }
    BIT(const vector<T>& a) : BIT((int)size(a)) {
        for (int i = 1; i <= n; ++i) ft[i] = G::op(ft[i - 1], a[i - 1]);
        for (int i = n; i >= 1; --i) ft[i] = G::op(G::inv(ft[i - b(i)]), ft[i]);
    }
    T query(int l, int r) { return G::op(G::inv(query(l)), query(r + 1)); }
    void update(int p, T value) {
        for (++p; p <= n; p += b(p)) ft[p] = G::op(ft[p], value);
    }
    // first r such that G::cmp(query(0, r), value) == false
    int lower_bound(T value) {
        T prefix = G::Id;
        int pos = 0;
        for (int x = h; x >= 0; --x) {
            if (pos + (1 << x) <= n && G::cmp(G::op(prefix, ft[pos + (1 << x)]), value) == true) {
                pos += 1 << x;
                prefix = G::op(prefix, ft[pos]);
            }
        }
        return pos;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<char, int>>> E(n + 1);
    for (int i = 1; i <= n; ++i) {
        int type, p = 0;
        cin >> type;
        if (type == 2) cin >> p;
        char c;
        cin >> c;
        E[p].emplace_back(c, i);
    }
    AhoCorasick aho;
    int m;
    cin >> m;
    vector<vector<int>> queries(n + 1);
    vector<int> st(m);
    for (int j = 0; j < m; ++j) {
        int i;
        string t;
        cin >> i >> t;
        int u = aho.add(t);
        queries[i].push_back(j);
        st[j] = u;
    }
    int d = (int)size(aho.trie);
    vector<vector<int>> F(d);
    vector<int> L(d), R(d);
    for (int u = d - 1; u > 0; --u) {
        if (not aho.trie[u].leaf) continue;
        int p = aho.getleaf(aho.getlink(u));
        F[p].push_back(u);
    }
    int timer = 0;
    auto tour = [&](auto& self, int u) -> void {
        L[u] = timer;
        for (auto v : F[u]) self(self, v);
        R[u] = timer++;
    };
    tour(tour, 0);
    BIT<G1<int>> bit(d + 1);
    vector<int> ans(m);
    auto dfs = [&](auto& self, int i, int u) -> void {
        int v = aho.getleaf(u);
        bit.update(R[v], +1);
        for (auto j : queries[i]) ans[j] = bit.query(L[st[j]], R[st[j]]);
        for (auto [c, j] : E[i]) self(self, j, aho.go(u, c));
        bit.update(R[v], -1);
    };
    dfs(dfs, 0, 0);
    for (int j = 0; j < m; ++j) cout << ans[j] << endl;
    exit(0);
}