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

constexpr int MOD = 1e9+7;

void run() {
    string s; cin >> s;
    ll ans = 1;

    vector<ll> dp(sz(s)+5);
    dp[0] = 1;
    dp[1] = 1;

    rep(i, 2, sz(dp)) {
        dp[i] = dp[i-1] + dp[i-2];
        if (dp[i] >= MOD) dp[i] -= MOD;
    }

    rep(i, 0, sz(s)) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0 << endl;
            return;
        }

        if (i > 0 && s[i] == s[i-1]) continue;
        if (s[i] != 'u' && s[i] != 'n') continue;

        int j = i;
        while (j < sz(s) && s[i] == s[j]) j++;

        ans *= dp[j-i];
        ans %= MOD;
    }

    cout << ans << endl;
}