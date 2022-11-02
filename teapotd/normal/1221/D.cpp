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

constexpr int MAX_N = 3e5+5;
constexpr int DIFF = 4;

ll dp[MAX_N][DIFF];

void solve() {
    int n; cin >> n;
    Vi hei(n), cost(n);

    rep(i, 0, n) {
        cin >> hei[i] >> cost[i];
    }

    rep(d, 0, DIFF) {
        dp[0][d] = cost[0] * ll(d);
    }

    rep(i, 1, n) rep(d, 0, DIFF) {
        ll best = 1e18;
        rep(d2, 0, DIFF) {
            if (hei[i-1]+d2 != hei[i]+d) {
                best = min(best, dp[i-1][d2]);
            }
        }
        dp[i][d] = best + cost[i]*ll(d);
    }

    ll ans = 1e18;
    rep(d, 0, DIFF) ans = min(ans, dp[n-1][d]);
    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}