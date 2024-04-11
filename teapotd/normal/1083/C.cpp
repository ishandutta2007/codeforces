#define _USE_MATH_DEFINES////////////////////////////////////////
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

struct LCA {
    vector<Vi> jumps;
    Vi level, pre, post;
    int cnt{0}, depth;

    LCA() {}

    LCA(vector<Vi>& G, int r) : jumps(sz(G)), level(sz(G)), pre(sz(G)), post(sz(G)) {
        dfs(G, r, -1);
        depth = int(log2(sz(G))) + 2;
        rep(j, 0, depth) rep(i, 0, sz(G)) jumps[i].pb(jumps[jumps[i][j]][j]);
    }

    void dfs(vector<Vi>& G, int i, int p) {
        level[i] = p < 0 ? 0 : level[p]+1;
        jumps[i].pb(p < 0 ? i : p);
        pre[i] = ++cnt;
        each(e, G[i]) if (e != p) dfs(G, e, i);
        post[i] = ++cnt;
    }

    bool isAncestor(int a, int b) {
        return pre[a] <= pre[b] && post[b] <= post[a];
    }

    int operator()(int a, int b) {
        for (int j = depth; j >= 0; j--) {
            if (!isAncestor(jumps[a][j], b)) a = jumps[a][j];
        }
        return isAncestor(a, b) ? a : jumps[a][0];
    }
};

int n, cnt;
vector<Vi> G;
LCA lca;
Vi perm;

struct Node {
    int high{-1}, low1{-1}, low2{-1};
    bool bad{0};

    Node() {}
    Node(int v) { high = low1 = v; }

    void addHigh(int v) {
        if (v != -1 && (high == -1 || lca.level[v] < lca.level[high])) {
            high = v;
        }
    }

    void addLow(int v) {
        if (v == -1) return;
        if (low1 != -1 && lca.isAncestor(v, low1)) return;
        if (low2 != -1 && lca.isAncestor(v, low2)) return;
        if (low1 == -1 || lca.isAncestor(low1, v)) {
            low1 = v;
            return;
        }
        if (low2 == -1 || lca.isAncestor(low2, v)) {
            low2 = v;
            return;
        }
        bad = 1;
    }

    void add(const Node& r) {
        addHigh(r.high);
        addLow(r.low1);
        addLow(r.low2);
        bad = bad || r.bad;
    }

    bool isBad() {
        if (bad) return 1;
        if (low2 != -1) {
            int lc = lca(low1, low2);
            return lca.level[lc] > lca.level[high];
        }
        return 0;
    }
};

vector<Node> tree;
int len;

void upd(int i) {
    tree[i] = tree[i*2];
    tree[i].add(tree[i*2+1]);
}

void updPath(int i) {
    i += len;
    while (i /= 2) upd(i);
}

Node query(int vb, int ve, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return {};
    if (b >= vb && e <= ve) return tree[i];
    int m = (b+e) / 2;
    Node tmp = query(vb, ve, i*2, b, m);
    tmp.add(query(vb, ve, i*2+1, m, e));
    return tmp;
}

int getMex() {
    int begin = 0, end = n+1;
    while (begin+1 < end) {
        int mid = (begin+end) / 2;
        if (query(0, mid).isBad()) {
            end = mid;
        } else {
            begin = mid;
        }
    }
    return begin;
}

void run() {
    cin >> n;
    perm.resize(n);
    G.resize(n);
    each(p, perm) cin >> p;

    rep(i, 1, n) {
        int p; cin >> p;
        G[p-1].pb(i);
    }

    lca = {G, 0};

    for (len = 1; len < n; len *= 2);
    tree.resize(len*2);

    rep(i, 0, n) {
        int p = perm[i];
        tree[len+p] = {i};
    }

    for (int i = len-1; i > 0; i--) {
        upd(i);
    }

    int q; cin >> q;

    while (q--) {
        int t; cin >> t;

        if (t == 2) {
            cout << getMex() << '\n';
        } else {
            int a, b; cin >> a >> b;
            a--; b--;
            swap(perm[a], perm[b]);
            swap(tree[len+perm[a]], tree[len+perm[b]]);
            updPath(perm[a]);
            updPath(perm[b]);
        }
    }
}