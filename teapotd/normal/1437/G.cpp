#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

constexpr char AMIN = 'a';
constexpr int ALPHA = 26;

struct Aho {
    vector<array<int, ALPHA>> nxt{1};
    Vi suf = {-1};

    int add(const string& str) {
        int i = 0;
        each(c, str) {
            if (!nxt[i][c-AMIN]) {
                nxt[i][c-AMIN] = sz(nxt);
                nxt.pb({}); suf.pb(-1);
            }
            i = nxt[i][c-AMIN];
        }
        return i;
    }

    void build() {
        queue<int> que;
        each(e, nxt[0]) if (e) {
            suf[e] = 0; que.push(e);
        }
        while (!que.empty()) {
            int i = que.front(), s = suf[i], j = 0;
            que.pop();
            each(e, nxt[i]) {
                if (e) que.push(e);
                (e ? suf[e] : e) = nxt[s][j++];
            }
        }
    }

    int next(int i, char c) {
        return nxt[i][c-AMIN];
    }
};

struct SegTree {
    using T = int;
    static constexpr T ID = INT_MIN;
    static T merge(T a, T b) { return max(a,b); }

    vector<T> V;
    int len;

    SegTree(int n = 0, T def = -1) {
        for (len = 1; len < n; len *= 2);
        V.resize(len*2, ID);
        rep(i, 0, n) V[len+i] = def;
        for (int i = len; --i;)
            V[i] = merge(V[i*2], V[i*2+1]);
    }

    void set(int i, T val) {
        V[i += len] = val;
        while (i /= 2) V[i] = merge(V[i*2], V[i*2+1]);
    }

    T query(int b, int e) {
        b += len; e += len-1;
        if (b > e)  return ID;
        if (b == e) return V[b];
        T x = merge(V[b], V[e]);
        while (b/2 < e/2) {
            if (~b&1) x = merge(x, V[b^1]);
            if (e&1)  x = merge(x, V[e^1]);
            b /= 2; e /= 2;
        }
        return x;
    }
};

constexpr SegTree::T SegTree::ID;

struct HLD {
    // Subtree of v = [pos[v]; pos[v]+size[v])
    // Chain with v = [chBegin[v]; chEnd[v])
    Vi par;     // Vertex parent
    Vi size;    // Vertex subtree size
    Vi depth;   // Vertex distance to root
    Vi pos;     // Vertex position in "HLD" order
    Vi chBegin; // Begin of chain with vertex
    Vi chEnd;   // End of chain with vertex
    Vi order;   // "HLD" preorder of vertices
    SegTree tree; // Verts are in HLD order

    HLD() {}

    HLD(vector<Vi>& G, int root)
            : par(sz(G)), size(sz(G)),
              depth(sz(G)), pos(sz(G)),
              chBegin(sz(G)), chEnd(sz(G)) {
        dfs(G, root, -1);
        decomp(G, root, -1, 0);
        tree = {sz(order)};
    }

    void dfs(vector<Vi>& G, int v, int p) {
        par[v] = p;
        size[v] = 1;
        depth[v] = p < 0 ? 0 : depth[p]+1;
        int& fs = G[v][0];
        if (fs == p) swap(fs, G[v].back());
        each(e, G[v]) if (e != p) {
            dfs(G, e, v);
            size[v] += size[e];
            if (size[e] > size[fs]) swap(e, fs);
        }
    }

    void decomp(vector<Vi>& G, int v, int p, int chb) {
        pos[v] = sz(order);
        chBegin[v] = chb;
        chEnd[v] = pos[v]+1;
        order.pb(v);
        each(e, G[v]) if (e != p) {
            if (e == G[v][0]) {
                decomp(G, e, v, chb);
                chEnd[v] = chEnd[e];
            } else {
                decomp(G, e, v, sz(order));
            }
        }
    }

    int chRoot(int v) {return order[chBegin[v]];}

    template<class T>
    void iterPath(int a, int b, T func) {
        while (chBegin[a] != chBegin[b]) {
            int ha = chRoot(a), hb = chRoot(b);
            if (depth[ha] > depth[hb]) {
                func(chBegin[a], pos[a]+1);
                a = par[ha];
            } else {
                func(chBegin[b], pos[b]+1);
                b = par[hb];
            }
        }
        if (pos[a] > pos[b]) swap(a, b);
        func(pos[a], pos[b]+1);
    }

    SegTree::T queryPath(int a, int b) {
        auto ret = SegTree::ID;
        iterPath(a, b, [&](int i, int j) {
            ret = SegTree::merge(ret, tree.query(i, j));
        });
        return ret;
    }
};

void run() {
    int n, m; cin >> n >> m;

    Aho aho;
    Vi acc(n);

    rep(i, 0, n) {
        string s; cin >> s;
        acc[i] = aho.add(s);
    }

    aho.build();

    Vi cur(n);
    vector<multiset<int>> elems(sz(aho.nxt));
    vector<Vi> tree(sz(aho.nxt));

    rep(i, 1, sz(aho.nxt)) {
        tree[i].pb(aho.suf[i]);
        tree[aho.suf[i]].pb(i);
    }

    HLD hld(tree, 0);

    each(i, acc) {
        hld.tree.set(hld.pos[i], 0);
        elems[i].insert(0);
    }

    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x;
            i--;
            elems[acc[i]].erase(elems[acc[i]].find(cur[i]));
            cur[i] = x;
            elems[acc[i]].insert(cur[i]);
            hld.tree.set(hld.pos[acc[i]], *elems[acc[i]].rbegin());
        } else {
            string q; cin >> q;
            int ans = -1, st = 0;
            each(c, q) {
                st = aho.next(st, c);
                ans = max(ans, hld.queryPath(0, st));
            }
            cout << ans << '\n';
        }
    }
}