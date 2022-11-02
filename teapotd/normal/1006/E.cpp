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
#define mp make_pair/////////////////////////////////////////////
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

vector<Vi> G;
Vi pre, post, order;

void dfs(int v) {
    pre[v] = sz(order);
    order.pb(v);
    each(e, G[v]) dfs(e);
    post[v] = sz(order);
}

void run() {
    int n, q; cin >> n >> q;
    G.resize(n);
    pre.resize(n);
    post.resize(n);

    rep(i, 1, n) {
        int p; cin >> p;
        G[p-1].pb(i);
    }

    dfs(0);
    deb(G, pre, post, order);

    rep(i, 0, q) {
        int u, k; cin >> u >> k;
        u--; k--;
        int ind = pre[u]+k;

        if (ind < post[u]) {
            cout << order[ind]+1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}