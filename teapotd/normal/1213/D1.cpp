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
    int k, n; cin >> n >> k;
    Vi elems(n);
    each(e, elems) cin >> e;

    vector<Vi> costs(2e5+5);

    each(e, elems) {
        int i = 0;
        for (; e != 0; i++, e /= 2) {
            costs[e].pb(i);
        }
        costs[0].pb(i);
    }

    int best = 1e9;

    each(vec, costs) {
        if (sz(vec) < k) continue;
        sort(all(vec));
        int alt = 0;
        rep(i, 0, k) alt += vec[i];
        best = min(best, alt);
    }

    cout << best << endl;
}