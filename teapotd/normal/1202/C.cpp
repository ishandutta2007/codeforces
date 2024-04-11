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

int valY(char c) { return (c == 'W') - (c == 'S'); }
int valX(char c) { return (c == 'D') - (c == 'A'); }

Vi prefMins(const Vi& vec) {
    Vi ret = {INT_MAX};
    each(k, vec) ret.pb(min(ret.back(), k));
    return ret;
}

Vi prefMaxs(const Vi& vec) {
    Vi ret = {INT_MIN};
    each(k, vec) ret.pb(max(ret.back(), k));
    return ret;
}

Vi sufMins(Vi vec) {
    reverse(all(vec));
    Vi ret = prefMins(vec);
    reverse(all(ret));
    return ret;
}

Vi sufMaxs(Vi vec) {
    reverse(all(vec));
    Vi ret = prefMaxs(vec);
    reverse(all(ret));
    return ret;
}

ll solve(string& s) {
    Vi posX = {0}, posY = {0};

    each(c, s) {
        posX.pb(posX.back() + valX(c));
        posY.pb(posY.back() + valY(c));
    }

    Vi prefMinsX = prefMins(posX), prefMinsY = prefMins(posY);
    Vi prefMaxsX = prefMaxs(posX), prefMaxsY = prefMaxs(posY);
    Vi sufMinsX = sufMins(posX), sufMinsY = sufMins(posY);
    Vi sufMaxsX = sufMaxs(posX), sufMaxsY = sufMaxs(posY);

    ll area = ll(prefMaxsX.back() - prefMinsX.back() + 1) * ll(prefMaxsY.back() - prefMinsY.back() + 1);

    rep(i, 1, sz(s)) {
        rep(dx, -1, 2) rep(dy, -1, 2) {
            if (abs(dx+dy) != 1) continue;

            int minX = min(prefMinsX[i+1], sufMinsX[i]+dx), minY = min(prefMinsY[i+1], sufMinsY[i]+dy);
            int maxX = max(prefMaxsX[i+1], sufMaxsX[i]+dx), maxY = max(prefMaxsY[i+1], sufMaxsY[i]+dy);
            ll alt = ll(maxX-minX+1) * ll(maxY-minY+1);
            area = min(area, alt);
        }
    }

    return area;
}

void run() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << solve(s) << '\n';
    }
}