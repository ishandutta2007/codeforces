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

void run() {
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> elems(n);
    each(e, elems) cin >> e;

    vector<ll> before(n+1), inside(n+1), after(n+1); // max suffix sum
    ll ans = 0;

    rep(i, 0, n) {
        before[i+1] = max(before[i]+elems[i], 0LL);
        inside[i+1] = max(before[i+1], max(inside[i]+elems[i]*x, 0LL));
        after[i+1] = max(inside[i+1], max(after[i]+elems[i], 0LL));
        ans = max(ans, max(before[i+1], max(inside[i+1], after[i+1])));
    }

    cout << ans << endl;
}