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

void solve() {
    int n; cin >> n;
    Vi elems(n);
    Vi prefs(n+1);

    each(e, elems) {
        cin >> e;
        e--;
        prefs[e+1] = 1;
    }

    rep(i, 1, n+1) prefs[i] += prefs[i-1];

    Vi from(n);
    set<int> seen;

    each(e, elems) {
        auto it = seen.upper_bound(e);
        if (it != seen.end()) {
            from[*it] = max(from[*it], e+1);
        }
        seen.insert(e);
    }

    int beg = 0;
    int ans = 0;

    rep(i, 0, n) {
        beg = max(beg, from[i]);
        ans = max(ans, prefs[i+1] - prefs[beg]);
    }

    cout << prefs.back()-ans << '\n';
}

void run() {
    int q; cin >> q;
    while (q--) solve();
}