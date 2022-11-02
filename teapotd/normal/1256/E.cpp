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

void run() {
    int n; cin >> n;
    vector<Pii> elems(n);

    rep(i, 0, n) {
        cin >> elems[i].x;
        elems[i].y = i;
    }

    vector<Pii> dp(n+1);
    sort(all(elems));

    rep(i, 1, n+1) {
        Pii best = {1e9, -1};
        rep(j, 3, 6) {
            if (i-j < 0) break;
            best = min(best, make_pair(dp[i-j].x + elems[i-1].x - elems[i-j].x, i-j));
        }
        dp[i] = best;
    }

    Vi ans(n);
    int nTeams = 0;

    for (int pref = n; pref > 0; pref = dp[pref].y) {
        nTeams++;
        rep(i, dp[pref].y, pref) ans[elems[i].y] = nTeams;
    }

    cout << dp[n].x << ' ' << nTeams << '\n';
    each(a, ans) cout << a << ' ';
    cout << '\n';
}