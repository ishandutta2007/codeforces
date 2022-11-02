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

ll steps[10][10][10][10]; // x, y, from, to

void run() {
    rep(x, 0, 10) rep(y, 0, 10) {
        auto &dp = steps[x][y];
        rep(i, 0, 10) rep(j, 0, 10) dp[i][j] = INT_MAX;
        rep(i, 0, 10) {
            dp[i][(i+x)%10] = 1;
            dp[i][(i+y)%10] = 1;
        }
        rep(i, 0, 10) rep(j, 0, 10) rep(k, 0, 10) {
            dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
        }
    }

    string s; cin >> s;

    rep(x, 0, 10) {
        rep(y, 0, 10) {
            int ans = -sz(s)+1;
            rep(i, 1, sz(s)) {
                int a = s[i-1]-'0', b = s[i]-'0';
                ll d = steps[x][y][a][b];
                if (d >= INT_MAX) {
                    ans = -1;
                    break;
                }
                ans += d;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
}