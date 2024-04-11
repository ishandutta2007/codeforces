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

int dp[2][1<<12];
int mat[12][100];

void handle() {
    int n, m; cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    rep(i, 0, n) rep(j, 0, m) cin >> mat[i][j];

    rep(col, 0, m) {
        auto &cur = dp[(col+1)%2], &last = dp[col%2];

        rep(mask, 0, 1<<n) {
            cur[mask] = last[mask];
            for (int here = mask; here > 0; here = (here-1) & mask) {
                rep(sh, 0, n) {
                    int alt = last[mask^here];
                    rep(b, 0, n) if ((here >> b) & 1) {
                        alt += mat[(b+sh)%n][col];
                    }
                    cur[mask] = max(cur[mask], alt);
                }
            }
        }
    }

    cout << dp[m%2][(1<<n)-1] << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) handle();
}