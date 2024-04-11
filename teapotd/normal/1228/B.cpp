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

int board[1005][1005];

void run() {
    int h, w; cin >> h >> w;

    rep(i, 0, h) {
        int r; cin >> r;
        rep(j, 0, r) board[i][j] = 1;
        board[i][r] = 2;
    }

    rep(j, 0, w) {
        int c; cin >> c;
        rep(i, 0, c) {
            if (board[i][j] == 2) {
                cout << "0\n";
                return;
            }
            board[i][j] = 1;
        }

        if (board[c][j] == 1) {
            cout << "0\n";
            return;
        }
        board[c][j] = 2;
    }

    constexpr int MOD = 1e9+7;
    int ans = 1;

    rep(i, 0, h) rep(j, 0, w) {
        if (board[i][j] == 0) {
            ans = (ans*2) % MOD;
        }
    }

    cout << ans << endl;
}