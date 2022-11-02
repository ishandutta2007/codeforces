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

string board[2005];
int ans[2005][2005];
int prefs[2005][2005];

template<class F, class G>
void solve(int n, int k, F in, G out) {
    rep(i, 0, n) {
        prefs[i][0] = 0;
        rep(j, 0, n) {
            prefs[i][j+1] = prefs[i][j] + in(i, j);
        }
    }

    int plus = 0;
    rep(i, 0, n) plus += (prefs[i][n] == 0);

    auto has = [&](int i, int j) {
        return prefs[i][j+k]-prefs[i][j] == prefs[i][n] && prefs[i][n] != 0;
    };

    rep(j, 0, n-k+1) {
        int cnt = plus;
        rep(i, 0, k) cnt += has(i, j);
        out(0, j) += cnt;

        rep(i, k, n) {
            cnt -= has(i-k, j);
            cnt += has(i, j);
            out(i-k+1, j) += cnt;
        }
    }
}

void run() {
    int n, k; cin >> n >> k;
    rep(i, 0, n) cin >> board[i];

    solve(n, k,
        [](int i, int j)->int { return board[i][j] == 'B'; },
        [](int i, int j)->int& { return ans[i][j]; });

    solve(n, k,
        [](int j, int i)->int { return board[i][j] == 'B'; },
        [](int j, int i)->int& { return ans[i][j]; });

    int ret = 0;
    rep(i, 0, n) rep(j, 0, n) ret = max(ret, ans[i][j]);
    cout << ret << endl;
}