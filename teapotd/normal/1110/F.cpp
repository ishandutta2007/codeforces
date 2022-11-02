#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

constexpr ll INF = 1e17;

struct SegmentTree {
    using T = ll;
    static constexpr T ID = 0;

    struct Node {
        T extra{ID};
        T small{INF};

        void init(T x, int) { small = x; }
        void merge(const Node& R) { small = min(small, R.small); }

        T apply(T x, int) {
            extra += x;
            small += x;
            return x;
        }
    };

    vector<Node> V;
    int len;
    SegmentTree(int n=0, T def=ID) {init(n,def);}

    void init(int n, T def) {
        for (len = 1; len < n; len *= 2);
        V.assign(len*2, {});
        rep(i, len, len+n) V[i].init(def, 1);
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
        T e = V[i].extra;
        if (e != ID) {
            e = V[L(i)].apply(e, size/2);
            V[R(i)].apply(e, size/2);
            V[i].extra = ID;
        }
    }

    T modify(int vBegin, int vEnd, T x, int i = 1, int begin = 0, int end = -1) {
        if (end < 0) end = len;
        if (vEnd <= begin || end <= vBegin) return x;
        if (vBegin <= begin && end <= vEnd) return V[i].apply(x, end-begin);

        int mid = (begin + end) / 2;
        push(i, end-begin);
        x = modify(vBegin,vEnd,x,L(i),begin,mid);
        x = modify(vBegin,vEnd,x,R(i),mid,end);
        update(i);
        return x;
    }

    Node query(int vBegin, int vEnd, int i = 1, int begin = 0, int end = -1) {
        if (end < 0) end = len;
        if (vEnd <= begin || end <= vBegin) return {};
        if (vBegin <= begin && end <= vEnd) return V[i];

        int mid = (begin + end) / 2;
        push(i, end-begin);
        Node x = query(vBegin,vEnd,L(i),begin,mid);
        x.merge(query(vBegin,vEnd,R(i),mid,end));
        return x;
    }
};

struct Vert {
    vector<Pii> E;
    Vi queries;
    int right;
};

struct Query {
    int v, l, r;
    ll ans;
};

vector<Vert> G;
vector<Query> queries;
SegmentTree tree;

void dfs(int i, ll d) {
    G[i].right = i;

    each(e, G[i].E) {
        dfs(e.x, d+e.y);
        G[i].right = max(G[i].right, G[e.x].right);
    }

    tree.modify(i, i+1, (G[i].E.empty() ? d : INF));
}

void solve(int i) {
    each(j, G[i].queries) {
        auto& q = queries[j];
        q.ans = tree.query(q.l, q.r).small;
    }

    each(e, G[i].E) {
        tree.modify(0, tree.len, e.y);
        tree.modify(e.x, G[e.x].right+1, -2*e.y);
        solve(e.x);
        tree.modify(0, tree.len, -e.y);
        tree.modify(e.x, G[e.x].right+1, 2*e.y);
    }
}

void run() {
    int n, q; cin >> n >> q;
    G.resize(n);
    tree.init(n, 0);

    rep(i, 1, n) {
        int p, w; cin >> p >> w;
        G[p-1].E.pb({i, w});
    }

    int ind = 0;
    queries.resize(q);

    each(x, queries) {
        cin >> x.v >> x.l >> x.r;
        x.v--;
        x.l--;
        G[x.v].queries.pb(ind++);
    }

    dfs(0, 0);
    solve(0);
    each(x, queries) cout << x.ans << '\n';
}