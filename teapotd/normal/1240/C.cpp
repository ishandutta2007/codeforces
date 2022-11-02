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

int n, k;
vector<vector<Pii>> G;
vector<ll> taken, nope;

void dfs(int v, int p) {
    ll sum = 0;
    vector<ll> diffs;

    each(e, G[v]) if (e.x != p) {
        dfs(e.x, v);
        sum += nope[e.x];
        diffs.pb(taken[e.x]-nope[e.x]+e.y);
    }

    sort(all(diffs));
    taken[v] = nope[v] = sum;
    int tot = 0;

    for (int i = sz(diffs)-1; i >= 0; i--) {
        ll d = diffs[i];
        if (d <= 0) break;
        if (tot >= k) break;

        nope[v] += d;
        if (tot < k-1) taken[v] += d;
        tot++;
    }
}

void solve() {
    cin >> n >> k;
    G.assign(n, {});

    rep(i, 1, n) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        G[a].pb({b, w});
        G[b].pb({a, w});
    }

    taken.assign(n, 0);
    nope.assign(n, 0);
    dfs(0, -1);
    cout << nope[0] << '\n';
}

void run() {
    int q; cin >> q;
    while (q--) solve();
}