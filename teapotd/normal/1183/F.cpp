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
    each(e, elems) cin >> e;

    sort(all(elems));
    elems.erase(unique(all(elems)), elems.end());
    reverse(all(elems));

    int ans = 0;

    rep(j, 0, 4) {
        Vi tmp;
        rep(i, 0, 3) {
            rep(k, j, sz(elems)) {
                int e = elems[k];
                bool ok = 1;
                each(a, tmp) {
                    if (a%e == 0 || e%a == 0) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    tmp.pb(e);
                    break;
                }
            }
        }
        ans = max(ans, accumulate(all(tmp), 0));
    }

    cout << ans << '\n';
}

void run() {
    int q; cin >> q;
    while (q--) solve();
}