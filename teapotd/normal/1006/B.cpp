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

#define prev rghbdfiodgjegrijoegr

constexpr int INF = 1e9;

int dp[2005][2005]; // pref, taken
int prev[2005][2005];

void run() {
    int n, k; cin >> n >> k;
    Vi elems(n);
    each(e, elems) cin >> e;

    dp[0][0] = 0;
    dp[0][1] = -INF;
    dp[1][1] = elems[0];

    rep(i, 1, n) {
        dp[i+1][1] = max(dp[i][1], elems[i]);
    }

    rep(taken, 2, k+1) {
        dp[0][taken] = -INF;

        rep(i, 1, n+1) {
            dp[i][taken] = dp[i-1][taken];
            prev[i][taken] = prev[i-1][taken];

            int alt = dp[i-1][taken-1] + elems[i-1];

            if (alt > dp[i][taken]) {
                dp[i][taken] = alt;
                prev[i][taken] = i-1;
            }
        }
    }

    cout << dp[n][k] << '\n';

    Vi ans;

    while (n > 0) {
        ans.pb(n-prev[n][k]);
        n = prev[n][k];
        k--;
    }

    reverse(all(ans));
    each(a, ans) cout << a << ' ';
    cout << '\n';
}