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


struct SegmentTree {
    using T = pair<int, bool>;
    static constexpr T ID = {0, false};

    struct Node {
        T extra{0, false};
        int zeroes{0};
        DBP(extra, zeroes);

        void init(T x) {
            extra = x;
            zeroes = (x.x == 0 || x.y);
        }

        void merge(const Node& R) {
            zeroes += R.zeroes;
        }

        T apply(T x, int size) {
            if (x.y) {
                extra = { 0, true };
                zeroes = size;
            }

            int ret = max(x.x-zeroes, 0);
            extra.x += x.x;
            zeroes = max(zeroes-x.x, 0);
            return { ret, x.y };
        }
    };

    vector<Node> V;
    int len;
    DBP(len, V);

    SegmentTree(int n=0, T def=ID) {init(n,def);}

    void init(int n, T def) {
        for (len = 1; len < n; len *= 2);
        V.assign(len*2, {});
        rep(i, len, len+n) V[i].init(def);
        for (int i = len-1; i > 0; i--) update(i);
    }

    int getChild(int i, int j) { return i*2+j; }
    int L(int i) { return getChild(i, 0); }
    int R(int i) { return getChild(i, 1); }

    void update(int i) {
        int a = L(i), b = R(i);
        V[i] = {};
        V[i].merge(V[a]);
        V[i].merge(V[b]);
    }

    void push(int i, int size) {
        if (V[i].extra != ID) {
            T e = V[L(i)].apply(V[i].extra, size/2);
            V[R(i)].apply(e, size/2);
            V[i].extra = ID;
        }
    }

    T modify(int vBegin, int vEnd, T x,
             int i = 1,
             int begin = 0, int end = -1) {
        if (end < 0) end = len;
        if (vEnd <= begin || end <= vBegin) return x;

        if (vBegin <= begin && end <= vEnd) {
            return V[i].apply(x, end-begin);
        }

        int mid = (begin + end) / 2;
        push(i, end-begin);
        x = modify(vBegin, vEnd, x, L(i), begin, mid);
        x = modify(vBegin, vEnd, x, R(i), mid, end);
        update(i);
        return x;
    }

    T query(int pos, int i = 1,
            int begin = 0, int end = -1) {
        if (end < 0) end = len;
        if (pos <= begin && end <= pos+1)
            return V[i].extra;

        int mid = (begin + end) / 2;
        push(i, end-begin);

        if (pos < mid) {
            return query(pos, L(i), begin, mid);
        }
        return query(pos, R(i), mid, end);
    }
};

constexpr SegmentTree::T SegmentTree::ID;

struct Vert {
    Vi E;
    int parent, size, depth, chain, chainPos;

    DBP(E, parent, depth, chain, chainPos);
};

struct Chain {
    Vi verts;
    vector<Pii> white;
    SegmentTree black;
    int lastBlack{1};

    DBP(verts, white, black);
};

int n, q;
vector<Vert> G;
vector<Chain> chains;
int changeTime = 0;

void hld(int i, int parent = -1, int d = 0) {
    int h = -1;
    G[i].parent = parent;
    G[i].depth = d;
    G[i].size = 1;

    each(e, G[i].E) if (e != parent) {
        hld(e, i, d+1);
        G[i].size += G[e].size;
        if (h < 0 || G[h].size < G[e].size) h = e;
    }

    if (h < 0) {
        h = sz(chains);
        chains.emplace_back();
    } else {
        h = G[h].chain;
    }
    chains[h].verts.pb(i);
    G[i].chain = h;

    if (parent < 0) {
        each(p, chains) {
            reverse(all(p.verts));
            rep(j, 0, sz(p.verts))
                G[p.verts[j]].chainPos = j;

            p.white.pb({ -1, -1 });
            p.black.init(sz(p.verts), {0, false});
        }
    }
}

void access(int v) {
    auto& chain = chains[G[v].chain];
    int head = G[chain.verts[0]].parent;

    if (head < 0) return;
    access(head);

    auto& parent = chains[G[head].chain];

    Pii white = *--upper_bound(all(parent.white), G[head].depth, [](int l, Pii r) {
        return l < r.x;
    });

    if (white.y > chain.white[0].y) {
        chain.white.clear();
        chain.white.pb(white);
        chain.black.modify(0, sz(chain.verts), {0, true});
        chain.lastBlack = 1;
    }

    int black = parent.black.query(G[head].chainPos).x - chain.lastBlack;
    if (black > 0) {
        chain.black.modify(0, sz(chain.verts), {black, false});
        chain.lastBlack += black;
    }
}

void opBlack(int v) {
    access(v);
    auto& chain = chains[G[v].chain];
    chain.black.modify(G[v].chainPos, sz(chain.verts), {1, false});
}

void opWhite(int v) {
    access(v);

    auto& chain = chains[G[v].chain];

    while (chain.white.back().x >= G[v].depth) {
        chain.white.pop_back();
    }

    chain.white.push_back({ G[v].depth, ++changeTime });
    chain.black.modify(G[v].chainPos, sz(chain.verts), {0, true});
}

void opQuery(int v) {
    access(v);

    auto& chain = chains[G[v].chain];
    int black = chain.black.query(G[v].chainPos).x;
    cout << (black ? "black\n" : "white\n");
}

void run() {
    cin >> n >> q;
    G.resize(n);

    rep(i, 1, n) {
        int j; cin >> j;
        G[i].E.pb(j-1);
        G[j-1].E.pb(i);
    }

    hld(0);
    deb(G);
    deb(chains);

    rep(i, 0, q) {
        int t, v; cin >> t >> v;
        if (t == 1) opBlack(v-1);
        else if (t == 2) opWhite(v-1);
        else if (t == 3) opQuery(v-1);
        else assert(0);
        deb(chains);
    }
}