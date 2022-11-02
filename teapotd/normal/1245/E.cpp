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

using dbl = long double;

int board[10][10];
dbl dp[10][10];
vector<Pii> way;

void run() {
    each(row, board) each(k, row) cin >> k;

    rep(r, 0, 10) {
        if (r % 2) {
            for (int c = 9; c >= 0; c--) way.pb({r, c});
        } else {
            rep(c, 0, 10) way.pb({r, c});
        }
    }

    rep(i, 1, sz(way)) {
        dbl sum = 0;
        int cnt = 0, fail = 0;

        rep(j, 1, 7) {
            if (i-j < 0) {
                fail++;
                continue;
            }

            Pii dst = way[i-j];
            int h = board[dst.x][dst.y];
            sum += min(dp[dst.x][dst.y], dp[dst.x-h][dst.y]);
            cnt++;
        }

        sum /= cnt;
        sum += dbl(6.0) / dbl(6-fail);
        dp[way[i].x][way[i].y] = sum;
    }

    cout << setprecision(10);
    cout << dp[way.back().x][way.back().y] << endl;
}