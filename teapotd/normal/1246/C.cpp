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

constexpr int MOD =  1e9+7;
constexpr int MAX_N = 2005;

int n, m;
vector<string> board;

int reachRight[MAX_N][MAX_N];
int reachDown[MAX_N][MAX_N];
ll waysRight[MAX_N][MAX_N];
ll waysDown[MAX_N][MAX_N];

void run() {
    cin >> n >> m;
    board.resize(n);
    each(r, board) cin >> r;

    if (n == 1 && m == 1) {
        cout << 1 << '\n';
        return;
    }

    rep(i, 0, n) {
        reachRight[i][m-1] = m;
        for (int j = m-2; j >= 0; j--) {
            reachRight[i][j] = reachRight[i][j+1] - (board[i][j+1] == 'R');
        }
    }

    rep(j, 0, m) {
        reachDown[n-1][j] = n;
        for (int i = n-2; i >= 0; i--) {
            reachDown[i][j] = reachDown[i+1][j] - (board[i+1][j] == 'R');
        }
    }

    waysRight[n-1][m-1] = waysDown[n-1][m-1] = 1;

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (i == n-1 && j == m-1) continue;

            waysRight[i][j] = waysDown[i][j+1] - waysDown[i][reachRight[i][j]] + waysRight[i+1][j];
            waysDown[i][j] = waysRight[i+1][j] - waysRight[reachDown[i][j]][j] + waysDown[i][j+1];
            waysRight[i][j] %= MOD;
            waysDown[i][j] %= MOD;
        }
    }

    ll ans = waysRight[0][0] - waysRight[1][0];
    ans += waysDown[0][0] - waysDown[0][1];

    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}