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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

struct SegTree {
    struct Node {
        int mex1{-1}, mex2{-1};
        int sum1{0}, sum2{0};
        int alt{-1};
        DBP(mex1, mex2, sum1, sum2, alt);
    };

    Node f(Node a, Node b) {
        if (a.alt == -1) return b;
        if (b.alt == -1) return a;
        Node c;
        c.mex1 = (b.mex1 == a.alt ? a.mex2 : a.mex1);
        c.mex2 = (b.mex2 == a.alt ? a.mex2 : a.mex1);
        c.sum1 = b.sum1 + (b.mex1 == a.alt ? a.sum2 : a.sum1);
        c.sum2 = b.sum2 + (b.mex2 == a.alt ? a.sum2 : a.sum1);
        c.alt = b.alt;
        return c;
    }

    vector<Node> V;
    int len;

    // Initialize tree for n elements; time: O(n)
    SegTree(int n = 0) {
        for (len = 1; len < n; len *= 2);
        V.resize(len*2);
        for (int i = len; --i;) V[i] = f(V[i*2], V[i*2+1]);
    }

    // Set element `i` to `val`; time: O(lg n)
    void set(int i, Node val) {
        V[i += len] = val;
        while (i /= 2) V[i] = f(V[i*2], V[i*2+1]);
    }

    void set(int i, int mex1, int mex2) {
        set(i, {mex1, mex2, mex1, mex2, mex1});
    }

    Node query(int vb, int ve, int i = 1, int b = 0, int e = -1) {
        if (e < 0) e = len;
        if (b >= ve || vb >= e) return {};
        if (b >= vb && e <= ve) return V[i];
        int m = (b+e) / 2;
        return f(query(vb, ve, i*2, b, m), query(vb, ve, i*2+1, m, e));
    }
};

constexpr int MAX_MEX = 22;

// Heavy-Light Decomposition of tree
// with subtree query support; space: O(n)
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

    vector<array<int, MAX_MEX>> cnt;
    int answer = 0;

    HLD() {}

    // Initialize structure for tree G
    // and given root; time: O(n lg n)
    // MODIFIES ORDER OF EDGES IN G!
    HLD(vector<Vi>& G, int root)
            : par(sz(G)), size(sz(G)),
              depth(sz(G)), pos(sz(G)),
              chBegin(sz(G)), chEnd(sz(G)) {
        dfs(G, root, -1);
        decomp(G, root, -1, 0);
        tree = {sz(order)};
        cnt.resize(sz(G));
        tree.set(0, 0, 1);
    }

    void dfs(vector<Vi>& G, int v, int p) {
        par[v] = p;
        size[v] = 1;
        depth[v] = p < 0 ? 0 : depth[p]+1;

        if (G[v].empty()) return;
        int& fs = G[v][0];
        if (fs == p) swap(fs, G[v].back());

        each(e, G[v]) if (e != p) {
            dfs(G, e, v);
            size[v] += size[e];
            if (size[e] > size[fs]) swap(e, fs);
        }
    }

    void decomp(vector<Vi>& G,
                int v, int p, int chb) {
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

    // Get root of chain containing v
    int chRoot(int v) {return order[chBegin[v]];}

    // Level Ancestor Query; time: O(lg n)
    int laq(int v, int level) {
        while (true) {
            int k = pos[v] - depth[v] + level;
            if (k >= chBegin[v]) return order[k];
            v = par[chRoot(v)];
        }
    }

    // Lowest Common Ancestor; time: O(lg n)
    int lca(int a, int b) {
        while (chBegin[a] != chBegin[b]) {
            int ha = chRoot(a), hb = chRoot(b);
            if (depth[ha] > depth[hb]) a = par[ha];
            else b = par[hb];
        }
        return depth[a] < depth[b] ? a : b;
    }

    // Call func(chBegin, chEnd) on each path
    // segment; time: O(lg n * time of func)
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
        // Remove +1 from pos[a]+1 for vertices
        // queries (with +1 -> edges).
        func(pos[a], pos[b]+1);
    }

    SegTree::Node pathMex(int v) {
        return tree.query(chBegin[v], chEnd[v]);
    }

    void add(int v) {
        int r = chRoot(v), p = par[r];

        auto tmp = pathMex(r);
        answer -= tmp.sum1;

        if (p != -1 && r != v) {
            cnt[p][tmp.mex1]--;
        }

        tree.set(pos[v], 0, 1);

        tmp = pathMex(r);
        answer += tmp.sum1;

        if (p != -1) {
            cnt[p][tmp.mex1]++;
        }

        while (p != -1) {
            v = p;
            r = chRoot(v);
            p = par[r];

            int m1 = 0;
            while (cnt[v][m1] > 0) m1++;
            int m2 = m1+1;
            while (cnt[v][m2] > 0) m2++;

            tmp = pathMex(r);
            answer -= tmp.sum1;

            if (p != -1) {
                cnt[p][tmp.mex1]--;
            }

            tree.set(pos[v], m1, m2);

            tmp = pathMex(r);
            answer += tmp.sum1;

            if (p != -1) {
                cnt[p][tmp.mex1]++;
            }
        }
    }
};

vector<Vi> tree;
HLD hld;

void run() {
    int q; cin >> q;
    tree.resize(q+1);

    rep(i, 0, q) {
        int p; cin >> p;
        tree[p-1].pb(i+1);
    }

    hld = {tree, 0};

    rep(i, 0, q) {
        hld.add(i+1);
        cout << hld.answer << '\n';
    }
}