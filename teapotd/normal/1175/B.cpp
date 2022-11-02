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
#define mp make_pair/////////////////////////////////////////////
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

constexpr ll MAX_V = (1LL << 32) - 1;

void run() {
    int l; cin >> l;

    vector<ll> mults;
    ll ans = 0, mult = 1;

    rep(i, 0, l) {
        string cmd; cin >> cmd;

        if (cmd == "add") {
            ans = min(ans+mult, MAX_V+5);
        } else if (cmd == "for") {
            ll n; cin >> n;
            mults.pb(mult);
            mult = min(mult*n, MAX_V+5);
        } else {
            mult = mults.back();
            mults.pop_back();
        }
    }

    if (ans > MAX_V) {
        cout << "OVERFLOW!!!\n";
    } else {
        cout << ans << '\n';
    }
}