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
    string s, t; cin >> s >> t;
    Vi pref(sz(s)+1), suf(sz(s)+1);

    rep(i, 0, sz(s)) {
        int p = pref[i];
        if (p < sz(t) && t[p] == s[i]) p++;
        pref[i+1] = p;
    }

    for (int i = sz(s)-1; i >= 0; i--) {
        int p = suf[i+1];
        if (p < sz(t) && t.rbegin()[p] == s[i]) p++;
        suf[i] = p;
    }

    deb(s, t, pref, suf);

    int ans = 0;
    int j = 0;

    rep(i, 0, sz(s)) {
        j = max(i, j);
        while (j < sz(s) && pref[i]+suf[j+1] >= sz(t)) j++;
        ans = max(ans, j-i);
    }

    cout << ans << endl;
}