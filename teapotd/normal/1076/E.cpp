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

struct SegmentTree {
    using T = ll;
    static constexpr T ID = 0;          // +

    struct Node {
        T extra{ID}; // Lazy propagated value
        T sum{0};

        void init(T x, int size) {
            sum = x*size;
        }

        void merge(const Node& R) {
            sum += R.sum;
        }

        T apply(T x, int size) {
            extra += x;
            sum += x*size;
            return x;
        }
    };

    vector<Node> V;
    int len;

    SegmentTree(int n=0, T def=ID) {init(n,def);}

    void init(int n, T def) {
        for (len = 1; len < n; len *= 2);

        // [STATIC] version
        V.assign(len*2, {});
        rep(i, len, len+n) V[i].init(def, 1);
        for (int i = len-1; i > 0; i--) update(i);
    }

    // [STATIC] version
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
        T e = V[i].extra;
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

// ---

struct Vert {
    Vi E;
    int depth{0}, pre{0}, post{0};
    ll ans{-1};
};

struct Event {
    int depth, begin, end, val;

    bool operator<(const Event& r) const {
        return depth < r.depth;
    }
};

vector<Vert> G;
vector<Vi> layers;
int pre{0};
SegmentTree tree;

void dfs(int i, int p, int d) {
    if (sz(layers) < d+1) {
        layers.resize(d+1);
    }

    layers[d].pb(i);
    G[i].depth = d;
    G[i].pre = pre++;

    each(e, G[i].E) if (e != p) {
        dfs(e, i, d+1);
    }

    G[i].post = pre;
}

void run() {
    int n; cin >> n;
    G.resize(n);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        G[a-1].E.pb(b-1);
        G[b-1].E.pb(a-1);
    }

    dfs(0, -1, 0);
    tree.init(n, 0);

    int m; cin >> m;
    vector<Event> events;

    rep(i, 0, m) {
        int v, d, x; cin >> v >> d >> x;
        v--;

        int depth = G[v].depth;
        events.pb({ depth, G[v].pre, G[v].post, x });
        events.pb({ depth+d+1, G[v].pre, G[v].post, -x });
    }

    sort(all(events));
    int j = 0;

    rep(i, 0, sz(layers)) {
        while (j < sz(events) && events[j].depth <= i) {
            tree.modify(events[j].begin, events[j].end, events[j].val);
            j++;
        }

        each(v, layers[i]) {
            G[v].ans = tree.query(G[v].pre, G[v].pre+1).sum;
        }
    }

    each(v, G) cout << v.ans << ' ';
    cout << endl;
}