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
    array<ll, 10> dmg = {}, old;
    rep(d, 1, 10) dmg[d] = -1e18;

    auto upd = [&](int i, ll d, vector<ll> kek) {
        bool dbl = 0;
        rep(j, 0, sz(kek)) {
            int ind = i-sz(kek)+j+1;
            ind %= 10;
            if (ind == 0) dbl = 1;
        }

        sort(all(kek));
        rep(j, 0, sz(kek)) {
            d += kek[j];
            if (dbl && j == sz(kek)-1) d += kek[j];
        }

        ll& k = dmg[i%10];
        k = max(k, d);
    };

    rep(i, 0, n) {
        int k; cin >> k;
        Vi cards[4];

        rep(j, 0, k) {
            int c, d; cin >> c >> d;
            cards[c].pb(d);
        }

        old = dmg;
        rep(j, 1, 4) sort(all(cards[j]));

        rep(d, 0, 10) {
            rep(j, 1, 4) {
                if (!cards[j].empty()) {
                    upd(d+1, old[d], {cards[j].back()});
                }
            }

            if (!cards[2].empty() && !cards[1].empty()) {
                upd(d+2, old[d], {cards[2].back(), cards[1].back()});
            }

            if (sz(cards[1]) >= 2) {
                upd(d+2, old[d], {cards[1].back(), cards[1].rbegin()[1]});
            }

            if (sz(cards[1]) >= 3) {
                upd(d+3, old[d], {cards[1].back(), cards[1].rbegin()[1], cards[1].rbegin()[2]});
            }
        }
    }

    ll ans = 0;
    each(d, dmg) ans = max(ans, d);
    cout << ans << endl;
}