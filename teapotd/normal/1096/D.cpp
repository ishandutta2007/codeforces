#include<bits/stdc++.h>/////////////////////////////////////////
#define deb(...)////////////////////////////////////////////////
#define DBP(...)////////////////////////////////////////////////
#ifdef LOC//////////////////////////////////////////////////////
#include"debuglib.h"////////////////////////////////////////////
#endif//////////////////////////////////////////////////////////
#define x first/////////////////////////////////////////////////
#define y second////////////////////////////////////////////////
#define pb push_back////////////////////////////////////////////
#define sz(x)int((x).size())////////////////////////////////////
#define each(a,x)for(auto&a:(x))////////////////////////////////
#define all(x)(x).begin(),(x).end()/////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)//////////////////////
using namespace std;using ll=int64_t;using Pii=pair<int,int>;///
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio//
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}///
//------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

const char* HARD = "hard";

void run() {
    int n; cin >> n;
    string str; cin >> str;
    Vi cost(n);
    each(c, cost) cin >> c;

    vector<array<ll, 4>> dp(n+1);
    fill(all(dp[0]), ll(1e18));
    dp[0][0] = 0;

    rep(i, 0, n) {
        rep(j, 0, 4) {
            dp[i+1][j] = dp[i][j] + cost[i];

            if (str[i] != HARD[j]) {
                if (j > 0 && str[i] == HARD[j-1]) {
                    dp[i+1][j] = min(dp[i+1][j], min(dp[i][j], dp[i][j-1]));
                } else {
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                }
            }
        }
    }

    ll ans = INT64_MAX;
    each(a, dp[n]) ans = min(ans, a);
    cout << ans << endl;
}