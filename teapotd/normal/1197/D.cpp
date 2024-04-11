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
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> elems(n);
    each(e, elems) cin >> e;

    vector<ll> cur(m, -1e18), last(m);
    ll ans = 0;
    cur[0] = 0;

    each(e, elems) {
        cur.swap(last);
        rep(r, 0, m) {
            int s = (r-1+m) % m;
            cur[r] = last[s] + e - k*(r == 1 || m == 1);
            if (r == 0) cur[r] = max(cur[r], 0ll);
            ans = max(ans, cur[r]);
        }
    }

    cout << ans << endl;
}