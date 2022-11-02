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

void run() {
    int n, m, k; cin >> n >> m >> k;
    Vi elems(n);
    each(e, elems) cin >> e;

    sort(all(elems));
    elems.resize(k);

    Vi offers(k+1, 0); // shovels count -> best offer
    rep(i, 0, m) {
        int x, y; cin >> x >> y;
        if (x <= k) {
            offers[x] = max(offers[x], y);
        }
    }

    vector<ll> prefs = {0};
    each(e, elems) prefs.pb(prefs.back()+e);

    vector<ll> dp(k+1);
    dp[0] = 0;

    rep(i, 1, k+1) {
        dp[i] = INT_MAX;
        rep(j, 0, i) {
            ll alt = dp[j] + prefs[i] - prefs[j+offers[i-j]];
            dp[i] = min(dp[i], alt);
        }
    }

    cout << dp.back() << endl;
}