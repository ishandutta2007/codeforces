#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

struct Elem {
    Pii min1{INT_MAX, INT_MAX}, min2{INT_MAX, INT_MAX}, max1{INT_MIN, INT_MIN}, max2{INT_MIN, INT_MIN};
    Elem() {}
    Elem(int vert, int pre) {
        min1 = max1 = { vert, pre };
    }

    void updateMin(Pii alt) {
        if (alt.y < min1.y) {
            min2 = min1;
            min1 = alt;
        } else if (alt.y < min2.y) {
            min2 = alt;
        }
    }

    void updateMax(Pii alt) {
        if (alt.y > max1.y) {
            max2 = max1;
            max1 = alt;
        } else if (alt.y > max2.y) {
            max2 = alt;
        }
    }
};

struct SegmentTree {
    using T = Elem;

    static T merge(T a, T b) {
        a.updateMin(b.min1);
        a.updateMin(b.min2);
        a.updateMax(b.max1);
        a.updateMax(b.max2);
        return a;
    }

    vector<T> V;
    int len;

    SegmentTree(int n=0, T def={}){init(n,def);}

    void init(int n, T def) {
        for (len = 1; len < n; len *= 2);
        V.assign(len+n, def);
        V.resize(len*2, {});
        for (int i = len-1; i > 0; i--) update(i);
    }

    void update(int i) {
        V[i] = merge(V[i*2], V[i*2+1]);
    }

    void set(int i, T val) {
        V[i+=len] = val;
        while ((i/=2) > 0) update(i);
    }

    T query(int begin, int end) {
        begin += len; end += len-1;
        if (begin > end)  return {};
        if (begin == end) return V[begin];
        T x = merge(V[begin], V[end]);

        while (begin/2 < end/2) {
            if (~begin&1) x = merge(x, V[begin^1]);
            if (end&1)    x = merge(x, V[end^1]);
            begin /= 2; end /= 2;
        }
        return x;
    }
};

// ---

struct Vert {
    Vi E, jumps;
    int level, pre, post;
};

vector<Vert> G;
int counter;

void initLCA(int i, int parent=-1, int d=0) {
    G[i].level = d;
    G[i].jumps.pb(parent < 0 ? i : parent);
    G[i].pre = ++counter;
    each(e, G[i].E) if (e != parent)
        initLCA(e, i, d+1);
    G[i].post = ++counter;

    if (parent < 0) {
        int depth = int(log2(sz(G))) + 2;
        rep(j, 0, depth) each(vert, G)
            vert.jumps.pb(G[vert.jumps[j]].jumps[j]);
    }
}

bool isAncestor(int a, int b) {
    return G[a].pre <= G[b].pre &&
           G[b].post <= G[a].post;
}

int lca(int a, int b) {
    for (int j = sz(G[a].jumps)-1; j >= 0; j--) {
        int k = G[a].jumps[j];
        if (!isAncestor(k, b)) a = k;
    }
    return isAncestor(a,b) ? a : G[a].jumps[0];
}

void run() {
    int n, q; cin >> n >> q;
    G.resize(n);

    rep(i, 1, n) {
        int p; cin >> p;
        G[p-1].E.pb(i);
        G[i].E.pb(p-1);
    }

    initLCA(0);
    SegmentTree tree(n);

    rep(i, 0, n) {
        tree.set(i, { i, G[i].pre });
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--;
        auto inter = tree.query(l, r);

        int vert = inter.min1.x;
        int level = G[lca(inter.min2.x, inter.max1.x)].level;
        int alt = G[lca(inter.min1.x, inter.max2.x)].level;

        if (alt > level) {
            vert = inter.max1.x;
            level = alt;
        }

        cout << vert+1 << ' ' << level << '\n';
    }
}