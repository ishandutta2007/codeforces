#define _USE_MATH_DEFINES
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

constexpr char AMIN = 'a'; // Smallest letter
constexpr int ALPHA = 26;  // Alphabet size

struct Fenwick {
    using T = int;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) { init(n); }
    void init(int n)   { s.assign(n, 0); }

    // A[i] = f(A[i], v); time: O(lg n)
    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    // Get f(A[0], .., A[i-1]); time: O(lg n)
    T query(int i) {
        T v = 0;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }
};

struct Aho {
    vector<array<int, ALPHA>> nxt{1};
    Vi suf = {-1}, accLink = {-1};
    vector<Vi> accept{1};

    // Add string with given ID to structure
    int add(const string& str, int id) {
        int i = 0;
        each(c, str) {
            if (!nxt[i][c-AMIN]) {
                nxt[i][c-AMIN] = sz(nxt);
                nxt.pb({}); suf.pb(-1);
                accLink.pb(1); accept.pb({});
            }
            i = nxt[i][c-AMIN];
        }
        accept[i].pb(id);
        return i;
    }

    // Build automata; time: O(V*ALPHA)
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
            accLink[i] = (accept[s].empty() ?
                    accLink[s] : s);
        }
    }

    // Append `c` to state `i`
    int next(int i, char c) {
        return nxt[i][c-AMIN];
    }

    // Call `f` for each pattern accepted
    // when in state `i` with its ID as argument.
    // Return true from `f` to terminate early.
    // Calls are in descreasing length order.
    template<class F> void accepted(int i, F f) {
        while (i != -1) {
            each(a, accept[i]) if (f(a)) return;
            i = accLink[i];
        }
    }
};

Vi elemToNode, counts, ans;
vector<array<int, 26>> edges;
vector<vector<Pii>> nodeToQueries;
Aho aho;
vector<Vi> sufEdges;
Vi pre, post;
int cnt = 0;
Fenwick seen;

void dfsSufs(int v) {
    pre[v] = cnt++;
    each(e, sufEdges[v]) dfsSufs(e);
    post[v] = cnt;
}

void dfs(int v, int st) {
    seen.modify(pre[st], 1);

    each(q, nodeToQueries[v]) {
        ans[q.x] = seen.query(post[q.y]) - seen.query(pre[q.y]);
    }

    rep(i, 0, ALPHA) {
        if (edges[v][i]) {
            dfs(edges[v][i], aho.nxt[st][i]);
        }
    }

    seen.modify(pre[st], -1);
}

void run() {
    int n; cin >> n;
    elemToNode.resize(n+1);
    edges.resize(1, {});

    rep(i, 1, n+1) {
        int t, p; cin >> t;
        char c;
        if (t == 1) {
            cin >> c;
            p = 0;
        } else {
            cin >> p >> c;
        }

        p = elemToNode[p];

        if (!edges[p][c-AMIN]) {
            edges[p][c-AMIN] = sz(edges);
            edges.emplace_back();
        }

        int e = edges[p][c-AMIN];
        elemToNode[i] = e;
    }

    int m; cin >> m;
    nodeToQueries.resize(sz(edges));

    rep(i, 0, m) {
        int id;
        string s;
        cin >> id >> s;
        int ahoId = aho.add(s, i);
        nodeToQueries[elemToNode[id]].pb({i, ahoId});
    }

    aho.build();
    sufEdges.resize(sz(aho.nxt));
    pre.resize(sz(aho.nxt));
    post.resize(sz(aho.nxt));
    rep(i, 1, sz(aho.nxt)) sufEdges[aho.suf[i]].pb(i);
    dfsSufs(0);
    seen.init(cnt);

    counts.resize(m);
    ans.resize(m);
    dfs(0, 0);
    each(a, ans) cout << a << '\n';
}