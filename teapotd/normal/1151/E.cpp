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

ll inters(ll n) {
    return n*(n-1)/2 + n;
}

void run() {
    ll n; cin >> n;
    vector<ll> elems(n);
    each(e, elems) cin >> e;

    ll ans = inters(n) - inters(elems[0]-1) - inters(n-elems[0]);

    rep(i, 1, n) {
        ll a = elems[i-1], x = elems[i];
        if (a == x) continue;

        if (a < x) {
            ans += (x-a) * (n-x+1);
        } else {
            ans += (a-x) * x;
        }
    }

    cout << ans << endl;
}