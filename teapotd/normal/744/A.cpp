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
vector<bool> seen;

ll ch2(ll n) {
    return n*(n-1) / 2;
}

int dfs(int v) {
    if (seen[v]) return 0;
    int ret = 1;
    seen[v] = 1;
    each(e, G[v]) ret += dfs(e);
    return ret;
}

void run() {
    int n, m, k; cin >> n >> m >> k;
    G.resize(n);

    Vi homes(k);
    each(h, homes) {
        cin >> h;
        h--;
    }

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    vector<Pii> kek;
    seen.resize(n);

    each(h, homes) {
        kek.pb({dfs(h), h});
    }

    sort(all(kek));

    ll ans = 0;
    int lol = 0;

    rep(i, 0, sz(kek)-1) {
        ans += ch2(kek[i].x);
        lol += kek[i].x;
    }

    ans += ch2(n-lol);

    cout << ans-m << endl;
}