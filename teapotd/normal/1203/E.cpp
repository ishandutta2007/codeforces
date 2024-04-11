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

int matching(vector<Vi>& G, Vi& match) {
    vector<bool> seen;
    int n = 0, k = 1;
    match.assign(sz(G), -1);

    function<int(int)> dfs = [&](int i) {
        if (seen[i]) return 0;
        seen[i] = 1;
        each(e, G[i]) {
            if (match[e] < 0 || dfs(match[e])) {
                match[i] = e; match[e] = i;
                return 1;
            }
        }
        return 0;
    };

    while (k) {
        seen.assign(sz(G), 0);
        k = 0;
        rep(i, 0, sz(G)) if (match[i] < 0)
            k += dfs(i);
        n += k;
    }
    return n;
}

void run() {
    int n; cin >> n;
    vector<Vi> G(n+150005);

    rep(i, 0, n) {
        int a; cin >> a;
        rep(j, max(a-1, 1), a+2) {
            G[i].pb(n+j);
            G[n+j].pb(i);
        }
    }

    Vi match;
    cout << matching(G, match) << endl;
}