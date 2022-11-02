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

ll dp[105][105][26]; // n, k, c

void run() {
    int n;
    ll k;
    string s;
    cin >> n >> k >> s;

    rep(i, 1, n+1) {
        int chr = s[i-1]-'a';
        rep(j, 1, n+1) rep(c, 0, 26) dp[i][j][c] = dp[i-1][j][c];
        rep(j, 1, n+1) rep(c, 0, 26) dp[i][j][chr] += dp[i-1][j-1][c];
        dp[i][1][chr]++;
        rep(j, 0, n+1) dp[i][j][chr] -= dp[i-1][j][chr];
    }

    ll ans = 0;
    dp[n][0][0] = 1;

    for (int len = n; len >= 0; len--) {
        ll cnt = 0;
        rep(c, 0, 26) cnt += dp[n][len][c];

        deb(len, cnt);

        if (cnt >= k) {
            ans += ll(n-len)*k;
            cout << ans << '\n';
            return;
        }

        ans += ll(n-len)*cnt;
        k -= cnt;
    }

    cout << -1 << endl;
}