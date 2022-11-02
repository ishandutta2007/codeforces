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
    string s, t, p;
    cin >> s >> t >> p;

    int cnt[26] = {0};

    each(c, s) cnt[c-'a']++;
    each(c, p) cnt[c-'a']++;
    each(c, t) cnt[c-'a']--;

    rep(i, 0, 26) {
        if (cnt[i] < 0) {
            cout << "NO\n";
            return;
        }
    }

    int i = 0;

    each(c, t) {
        if (c == s[i]) {
            if (++i == sz(s)) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}