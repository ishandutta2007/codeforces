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
    ll n; cin >> n;
    Vi repr;

    while (n) {
        repr.pb(int(n%3));
        n /= 3;
    }

    for (int i = sz(repr)-1; i >= 0; i--) {
        if (repr[i] == 2) {
            int best = sz(repr);
            rep(j, i+1, sz(repr)) {
                if (repr[j] == 0) {
                    best = j;
                    break;
                }
            }

            rep(j, 0, best) repr[j] = 0;
            if (best < sz(repr)) repr[best] = 1;
            else repr.pb(1);
            break;
        }
    }

    ll ans = 0;

    for (int i = sz(repr)-1; i >= 0; i--) {
        ans = ans*3 + repr[i];
    }

    cout << ans << '\n';
}

void run() {
    int q; cin >> q;
    while (q--) solve();
}