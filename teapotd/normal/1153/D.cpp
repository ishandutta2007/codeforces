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

struct Vert {
    Vi E;
    int type; // 0 = min, 1 = max
    int dp, leaves;
};

vector<Vert> G;

void solve(int i) {
    if (sz(G[i].E) == 0) {
        G[i].dp = 0;
        G[i].leaves = 1;
        return;
    }

    each(e, G[i].E) G[i].leaves += G[e].leaves;

    if (G[i].type == 1) {
        G[i].dp = 0;
        each(e, G[i].E) {
            int alt = G[i].leaves - (G[e].leaves-G[e].dp);
            G[i].dp = max(G[i].dp, alt);
        }
    } else {
        G[i].dp = 0;
        each(e, G[i].E) {
            G[i].dp += G[e].dp;
        }
    }
}

void run() {
    int n; cin >> n;
    G.resize(n);

    rep(i, 0, n) {
        cin >> G[i].type;
    }

    rep(i, 1, n) {
        int p; cin >> p;
        G[p-1].E.pb(i);
    }

    for (int i = n-1; i >= 0; i--) {
        solve(i);
    }

    cout << G[0].dp+1 << endl;
}