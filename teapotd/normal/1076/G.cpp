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

using Func = array<int, 6>;

int m;

Func compose(Func f, Func g) { // f(g(x))
    rep(i, 0, m+1) g[i] = f[g[i]];
    return g;
}

struct SegmentTree {
    using T = bool;
    static constexpr bool ID = 0;

    struct Node {
        bool extra{ID};
        Func mapping, invMapping;

        Node() {
            rep(i, 0, m+1) mapping[i] = invMapping[i] = i;
        }

        void init() { // Even on start
            rep(i, 0, m) mapping[i] = invMapping[i] = i+1;
            mapping[m] = m;
            invMapping[m] = 0;
        }

        // Merge with node R on the right
        void merge(const Node& R) {
            mapping = compose(mapping, R.mapping);
            invMapping = compose(invMapping, R.invMapping);
        }

        // Apply modification to node, return
        // value to be applied to node on right
        T apply(bool x, int) {
            if (x) {
                swap(mapping, invMapping);
                extra = !extra;
            }
            return x;
        }
    };

    vector<Node> V;
    int len;

    SegmentTree(int n = 0) { init(n); }

    void init(int n) {
        for (len = 1; len < n; len *= 2);
        V.assign(len*2, {});
        rep(i, len, len+n) V[i].init();
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
        int e = V[i].extra;
        if (e != ID) {
            e = V[L(i)].apply(e, size/2);
            V[R(i)].apply(e, size/2);
            V[i].extra = ID;
        }
    }

    // Modify [vBegin;end) with x; time: O(lg n)
    T modify(int vBegin, int vEnd, T x,
             int i = 1,
             int begin = 0, int end = -1) {
        if (end < 0) end = len;
        if (vEnd <= begin || end <= vBegin)
            return x;

        if (vBegin <= begin && end <= vEnd) {
            return V[i].apply(x, end-begin);
        }

        int mid = (begin + end) / 2;
        push(i, end-begin);
        x = modify(vBegin,vEnd,x,L(i),begin,mid);
        x = modify(vBegin,vEnd,x,R(i),mid,end);
        update(i);
        return x;
    }

    // Query [vBegin;vEnd); time: O(lg n)
    // Returns base nodes merged together
    Node query(int vBegin, int vEnd, int i = 1,
               int begin = 0, int end = -1) {
        if (end < 0) end = len;
        if (vEnd <= begin || end <= vBegin)
            return {};
        if (vBegin <= begin && end <= vEnd)
            return V[i];

        int mid = (begin + end) / 2;
        push(i, end-begin);
        Node x = query(vBegin,vEnd,L(i),begin,mid);
        x.merge(query(vBegin,vEnd,R(i),mid,end));
        return x;
    }
};

void run() {
    int n, q; cin >> n >> m >> q;
    SegmentTree tree(n);

    rep(i, 0, n) {
        ll a; cin >> a;
        if (a%2) tree.modify(i, i+1, true);
    }

    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        l--;

        if (t == 1) {
            ll d; cin >> d;
            if (d%2) tree.modify(l, r, true);
        } else {
            auto f = tree.query(l, r).mapping;
            cout << (f[m] > 0 ? 1 : 2) << '\n';
        }
    }
}