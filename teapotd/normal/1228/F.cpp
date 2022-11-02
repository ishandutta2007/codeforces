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

int n;
vector<Vi> G;
Vi dist, par, ans, bin, fixes;
bool ok;

void dfs1(int v, int p, int d) {
    par[v] = p;
    dist[v] = d;
    each(e, G[v]) if (e != p) dfs1(e, v, d+1);
}

void dfs2(int v, int p) {
    Vi children;

    each(e, G[v]) if (e != p) {
        dfs2(e, v);
        children.pb(bin[e]);
    }

    if (children.empty()) {
        bin[v] = 0;
        return;
    } else if (sz(children) == 1) {
        if (children[0] == 0) {
            bin[v] = 1;
            fixes.pb(v);
        }
    } else if (sz(children) == 2) {
        if (children[0] == children[1]) {
            bin[v] = children[0]+1;
        } else {
            ok = 0;
        }
    } else if (sz(children) == 3) {
        sort(all(children));
        if (children[0] == children[1] && children[0]+1 == children[2]) {
            bin[v] = children[2]+1;
            fixes.pb(v);
        } else {
            ok = 0;
        }
    } else {
        ok = 0;
    }
}

void check(int root) {
    ok = 1;
    fixes.clear();
    bin.assign(sz(G), -1);
    dfs2(root, -1);
    if (ok && sz(fixes) == 1) {
        ans.pb(fixes[0]);
    }
}

void run() {
    cin >> n;
    G.resize((1<<n) - 2);

    rep(i, 0, sz(G)-1) {
        int a, b; cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    dist.resize(sz(G));
    par.resize(sz(G));

    dfs1(0, -1, 0);
    int far = 0;
    rep(i, 0, sz(G)) if (dist[i] > dist[far]) far = i;
    dfs1(far, -1, 0);
    rep(i, 0, sz(G)) if (dist[i] > dist[far]) far = i;

    Vi diam;
    while (far != -1) {
        diam.pb(far);
        far = par[far];
    }

    check(diam[sz(diam)/2-1]);
    check(diam[sz(diam)/2]);

    cout << sz(ans) << '\n';
    sort(all(ans));
    each(a, ans) cout << a+1 << ' ';
    cout << '\n';
}