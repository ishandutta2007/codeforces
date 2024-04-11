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

constexpr ll INF = 1e12;
constexpr int MAX_N = 30001;

ll dpF[2][MAX_N][3], dpG[2][MAX_N][3][3];

ll& f(int k, int n, int s2) { return dpF[k%2][n][s2+1]; }
ll& g(int k, int n, int s1, int s2) { return dpG[k%2][n][s1+1][s2+1]; }

void run() {
    int n, k; cin >> n >> k;

    vector<ll> prefs = {0};
    rep(i, 0, n) {
        int e; cin >> e;
        prefs.pb(prefs.back() + e);
    }

    rep(i, 0, n+1) {
        rep(s1, -1, 2) rep(s2, -1, 2) g(0, i, s1, s2) = -INF;
        f(0, i, 0) = 0;
        f(0, i, -1) = f(0, i, 1) = -INF;
    }

    rep(j, 1, k+1) {
        rep(i, 0, n+1) rep(s1, -1, 2) rep(s2, -1, 2) {
            ll& cur = g(j, i, s1, s2) = -INF;
            if (i > 0) cur = max(cur, g(j, i-1, s1, s2));
            if (s1 != 0 || j == 1) cur = max(cur, f(j-1, i, s1) + (s1-s2)*prefs[i]);
        }

        rep(s2, -1, 2) {
            f(j, 0, s2) = -INF;
            rep(i, 1, n+1) {
                ll& cur = f(j, i, s2) = f(j, i-1, s2);
                rep(s1, -1, 2) cur = max(cur, g(j, i-1, s1, s2) + (s2-s1)*prefs[i]);
            }
        }
    }

    cout << f(k, n, 0) << endl;
}