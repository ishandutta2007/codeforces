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

ll dp[40][2][2][2][2]; // bits count, is a == l, is a == r, is b == l, is b == r

Vi getBin() {
    int k; cin >> k;
    Vi tmp;
    rep(i, 0, 35) {
        tmp.pb(k%2);
        k /= 2;
    }
    reverse(all(tmp));
    return tmp;
}

void solve() {
    Vi l = getBin();
    Vi r = getBin();

    memset(dp, 0, sizeof(dp));
    dp[1][1][1][1][1] = 1;

    rep(n, 1, sz(l)) {
        rep(i, 0, 2) rep(j, 0, 2) rep(u, 0, 2) rep(v, 0, 2) {
            rep(a, 0, 2) rep(b, 0, 2) {
                if (a+b > 1) continue;
                if (i && a < l[n]) continue;
                if (j && a > r[n]) continue;
                if (u && b < l[n]) continue;
                if (v && b > r[n]) continue;
                dp[n+1][i && a == l[n]][j && a == r[n]][u && b == l[n]][v && b == r[n]] += dp[n][i][j][u][v];
            }
        }
    }

    ll ans = 0;
    rep(i, 0, 2) rep(j, 0, 2) rep(u, 0, 2) rep(v, 0, 2) ans += dp[sz(l)][i][j][u][v];
    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}