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

void solve() {
    int n, m; cin >> n >> m;
    vector<string> M(n);
    each(s, M) cin >> s;

    Vi rows(n), cols(m);

    rep(i, 0, n) rep(j, 0, m) {
        if (M[i][j] == '.') {
            rows[i]++;
            cols[j]++;
        }
    }

    int best = INT_MAX;

    rep(i, 0, n) rep(j, 0, m) {
        int alt = rows[i] + cols[j] - (M[i][j] == '.');
        best = min(best, alt);
    }

    cout << best << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}