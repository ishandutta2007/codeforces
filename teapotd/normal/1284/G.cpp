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

// Find largest subset S of [n] such that
// S is independent in both matroid A and B.
// A and B are given by their oracles,
// see example implementations below.
// Returns vector V such that V[i] = 1 iff
// i-th element is included in found set;
// time: O(r^2*init + r^2*n*add),
// where r is max independent set,
// `init` is max time of oracles init
// and `add` is max time of oracles canAdd.
template<class T, class U>
vector<bool> intersectMatroids(T& A, U& B,
                                 int n) {
    vector<bool> ans(n);
    bool ok = 1;

    A.init(ans);
    B.init(ans);
    rep(i, 0, n) if (A.canAdd(i) && B.canAdd(i))
        ans[i] = 1, A.init(ans), B.init(ans);

    while (ok) {
        vector<Vi> G(n);
        vector<bool> good(n);
        queue<int> que;
        Vi prev(n, -1);

        A.init(ans);
        B.init(ans);
        ok = 0;

        rep(i, 0, n) if (!ans[i]) {
            if (A.canAdd(i)) que.push(i), prev[i]=-2;
            good[i] = B.canAdd(i);
        }

        rep(i, 0, n) if (ans[i]) {
            ans[i] = 0;
            A.init(ans);
            B.init(ans);
            rep(j, 0, n) if (i != j && !ans[j]) {
                if (A.canAdd(j)) G[i].pb(j);
                if (B.canAdd(j)) G[j].pb(i);
            }
            ans[i] = 1;
        }

        while (!que.empty()) {
            int i = que.front();
            que.pop();

            if (good[i]) {
                ans[i] = 1;
                while (prev[i] >= 0) {
                    ans[i = prev[i]] = 0;
                    ans[i = prev[i]] = 1;
                }
                ok = 1;
                break;
            }

            each(j, G[i]) if (prev[j] == -1)
                que.push(j), prev[j] = i;
        }
    }

    return ans;
}

// Matroid where each element has color
// and set is independent iff for each color c
// #{elements of color c} <= maxAllowed[c].
struct LimOracle {
    Vi color; // color[i] = color of i-th element
    Vi maxAllowed; // Limits for colors
    Vi tmp;

    // Init oracle for independent set S; ~O(n)
    void init(vector<bool>& S) {
        tmp = maxAllowed;
        rep(i, 0, sz(S)) tmp[color[i]] -= S[i];
    }

    // Check if S+{k} is independent; time: O(1)
    bool canAdd(int k) {
        return tmp[color[k]] > 0;
    }
};

// Co-graphic matroid - each element is edge,
// set is independent iff after removing edges
// from graph number of connected components
// doesn't change.
struct CographOracle {
    vector<Pii> elems; // Ground set: graph edges
    int n; // Number of vertices, indexed [0;n-1]
    vector<Vi> G;
    Vi pre, low;
    int cnt;

    int dfs(int v, int p) {
        pre[v] = low[v] = ++cnt;
        each(e, G[v]) if (e != p)
            low[v] = min(low[v], pre[e] ?: dfs(e,v));
        return low[v];
    }

    // Init oracle for independent set S; O(n)
    void init(vector<bool>& S) {
        G.assign(n, {});
        pre.assign(n, 0);
        low.resize(n);
        cnt = 0;
        rep(i, 0, sz(S)) if (!S[i]) {
            Pii e = elems[i];
            G[e.x].pb(e.y);
            G[e.y].pb(e.x);
        }
        rep(v, 0, n) if (!pre[v]) dfs(v, -1);
    }

    // Check if S+{k} is independent; time: O(1)
    bool canAdd(int k) {
        Pii e = elems[k];
        return max(pre[e.x], pre[e.y])
            != max(low[e.x], low[e.y]);
    }
};

// ---

void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    each(row, mat) cin >> row;

    LimOracle lim;
    CographOracle graph;
    vector<Pii> edgeMap;

    lim.maxAllowed.resize(n*m, -2);
    graph.n = n*m;

    auto consider = [&](int a, int b, int i, int j, int dstX, int dstY) {
        if (mat[i][j] != 'O') return;
        int c = (a+b) % 2 ? i*m+j : a*m+b;
        lim.color.pb(c);
        lim.maxAllowed[c]++;
        graph.elems.pb({a*m+b, i*m+j});
        edgeMap.pb({dstX, dstY});
    };

    rep(i, 0, n) rep(j, 0, m) if (mat[i][j] == 'O') {
        if (i+1 < n) consider(i, j, i+1, j, i*2+1, j*2);
        if (j+1 < m) consider(i, j, i, j+1, i*2, j*2+1);
    }

    int cells = 0;

    rep(i, 0, n) rep(j, 0, m) if (mat[i][j] == 'O') {
        if ((i+j) % 2 == 0 && i+j > 0) {
            if (lim.maxAllowed[i*m+j] < 0) {
                cout << "NO\n";
                return;
            }
        } else {
            lim.maxAllowed[i*m+j] = 1e6;
        }
        cells++;
    }

    auto inter = intersectMatroids(graph, lim, sz(graph.elems));

    if (count(all(inter), 0) != cells-1) {
        cout << "NO\n";
        return;
    }

    vector<string> ans(n*2-1, string(m*2-1, ' '));
    rep(i, 0, n) rep(j, 0, m) ans[i*2][j*2] = mat[i][j];

    rep(i, 0, sz(inter)) if (!inter[i]) {
        auto& p = edgeMap[i];
        ans[p.x][p.y] = 'O';
    }

    cout << "YES\n";
    each(row, ans) cout << row << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}