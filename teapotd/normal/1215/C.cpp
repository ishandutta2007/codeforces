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
    string s, t; cin >> s >> t;

    Vi ab, ba;

    rep(i, 0, n) {
        if (s[i] == 'a' && t[i] == 'b') ab.pb(i);
        else if (s[i] == 'b' && t[i] == 'a') ba.pb(i);
    }

    if ((sz(ab)+sz(ba)) % 2) {
        cout << -1 << endl;
        return;
    }

    vector<Pii> ans;

    if (sz(ab) % 2) {
        ans.pb({ab.back(), ab.back()});
        ba.pb(ab.back());
        ab.pop_back();
    }

    for (int i = 0; i < sz(ab); i += 2) {
        ans.pb({ab[i], ab[i+1]});
    }

    for (int i = 0; i < sz(ba); i += 2) {
        ans.pb({ba[i], ba[i+1]});
    }

    cout << sz(ans) << '\n';
    each(a, ans) cout << a.x+1 << ' ' << a.y+1 << '\n';
}