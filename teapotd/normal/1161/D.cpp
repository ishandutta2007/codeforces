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

constexpr int MOD = 998244353;

struct Vert {
    vector<Pii> E;
    int label{-1};
    bool seen{0};
};

vector<Vert> G;

void addEdge(int i, int j, int x) {
    G[i].E.pb({j, x});
    G[j].E.pb({i, x});
}

bool dfs(int i) {
    G[i].seen = 1;

    each(e, G[i].E) {
        int wanted = G[i].label ^ e.y;
        if (G[e.x].label != -1 && wanted != G[e.x].label) return 0;

        if (!G[e.x].seen) {
            G[e.x].label = wanted;
            if (!dfs(e.x)) return 0;
        }
    }

    return 1;
}

ll solve() {
    ll ret = 1;

    rep(i, 0, sz(G)) {
        if (G[i].seen || G[i].label == -1) continue;
        if (!dfs(i)) return 0;
    }

    rep(i, 0, sz(G)) {
        if (G[i].seen) continue;
        G[i].label = 0;
        if (!dfs(i)) return 0;
        ret = (ret*2) % MOD;
    }

    return ret;
}

void run() {
    string s; cin >> s;
    ll ans = 0;

    rep(len, 1, sz(s)) {
        G.assign(sz(s)+len, {});
        G[sz(s)].label = 1;

        rep(i, 0, sz(s)-len) {
            if (s[i] != '?') {
                G[i].label = s[i]-'0';
            }
        }

        rep(i, 0, len) {
            if (s[sz(s)-len+i] != '?') {
                addEdge(sz(s)-len+i, sz(s)+i, s[sz(s)-len+i]-'0');
            }
        }

        rep(i, 0, sz(s)/2) addEdge(i, sz(s)-i-1, 0);
        rep(i, 0, len/2) addEdge(sz(s)+i, sz(s)+len-i-1, 0);

        ans += solve();
    }

    cout << ans%MOD << endl;
}