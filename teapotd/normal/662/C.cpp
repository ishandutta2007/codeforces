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

int cube[1<<20];
int dp[2][1<<20][22];

void run() {
    int n, m; cin >> n >> m;
    vector<string> board(n);
    each(e, board) cin >> e;

    rep(i, 0, m) {
        int mask = 0;
        rep(j, 0, n) if (board[j][i] == '1') mask |= 1<<j;
        cube[mask]++;
    }

    rep(i, 0, 1<<n) rep(j, 0, n+1) dp[0][i][j] = cube[i] * abs(n - j*2);

    rep(k, 0, n) {
        auto &cur = dp[(k+1)%2], &prev = dp[k%2];
        rep(mask, 0, 1<<n) rep(j, 0, n-k) {
            int bit = mask & (1<<k);
            int m0 = (mask & ~(1<<k)), m1 = mask | (1<<k);
            cur[mask][j] = prev[m0^bit][j] + prev[m1^bit][j+1];
        }
    }

    int diff = 0;
    rep(i, 0, 1<<n) diff = max(diff, dp[n%2][i][0]);

    int ans = (n*m - diff) / 2;
    cout << ans << endl;
}