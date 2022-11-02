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

struct SAT2 : Vi {
    vector<Vi> G;
    Vi order, flags;

    // Init n variables, you can add more later
    SAT2(int n = 0) : G(n*2) {}

    // Add new var and return its index
    int addVar() {
        G.resize(sz(G)+2); return sz(G)/2;
    }

    // Add (i => j) constraint
    void imply(int i, int j) {
        i = max(i*2-1, -i*2-2);
        j = max(j*2-1, -j*2-2);
        G[i].pb(j); G[j^1].pb(i^1);
    }

    // Add (i v j) constraint
    void either(int i, int j) { imply(-i, j); }

    // Constraint at most one true variable
    void atMostOne(Vi& vars) {
        int x = addVar();
        each(i, vars) {
            int y = addVar();
            imply(x, y); imply(i, -x); imply(i, y);
            x = y;
        }
    }

    // Solve and save assignments in `values`
    bool solve() { // O(n+m), Kosaraju is used
        assign(sz(G)/2+1, -1);
        flags.assign(sz(G), 0);
        rep(i, 0, sz(G)) dfs(i);
        while (!order.empty()) {
            if (!propag(order.back()^1, 1)) return 0;
            order.pop_back();
        }
        return 1;
    }

    void dfs(int i) {
        if (flags[i]) return;
        flags[i] = 1;
        each(e, G[i]) dfs(e);
        order.pb(i);
    }

    bool propag(int i, bool first) {
        if (!flags[i]) return 1;
        flags[i] = 0;
        if (at(i/2+1) >= 0) return first;
        at(i/2+1) = i&1;
        each(e, G[i]) if (!propag(e, 0)) return 0;
        return 1;
    }
};

void run() {
    int n, p, M, m; cin >> n >> p >> M >> m;
    SAT2 sat(p+M+1); // 1-p stations, p+1 to p+M+1 freq

    rep(i, 1, M+1) {
        sat.imply(p+i, p+i+1);
    }

    rep(i, 0, n) {
        int x, y; cin >> x >> y;
        sat.either(x, y);
    }

    rep(i, 1, p+1) {
        int l, r; cin >> l >> r;
        sat.imply(i, -p-l);
        sat.imply(i, p+r+1);
    }

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        sat.either(-u, -v);
    }

    if (!sat.solve()) {
        cout << -1 << endl;
        return;
    }

    int f = 1;
    rep(i, 1, M+2) if (sat[p+i]) {
        f = i-1;
        break;
    }

    f = max(f, 1);

    Vi ans;
    rep(i, 1, p+1) if (sat[i]) ans.pb(i);

    cout << sz(ans) << ' ' << f << '\n';
    each(a, ans) cout << a << ' ';
    cout << '\n';
 }