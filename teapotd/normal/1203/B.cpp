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

bool solve() {
    int n; cin >> n;
    Vi elems(n*4);
    each(e, elems) cin >> e;

    Vi cnt(1e4+5), nonz;
    each(e, elems) {
        if (cnt[e]++ == 0) nonz.pb(e);
    }

    rep(i, 1, n*4) {
        int area = elems[0]*elems[i];
        bool ok = 1;

        each(a, nonz) {
            if (area % a) ok = 0;
            else if (cnt[a] % 2) ok = 0;
            else if (sz(cnt) <= area/a) ok = 0;
            else if (cnt[a] != cnt[area/a]) ok = 0;
        }

        if (ok) return 1;
    }

    return 0;
}

void run() {
    int q; cin >> q;
    while (q--) cout << (solve() ? "YES\n" : "NO\n");
}