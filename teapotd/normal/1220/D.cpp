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
    vector<ll> elems[64];

    rep(j, 0, n) {
        ll k; cin >> k;
        int i = 0;
        while (k%2 == 0) {
            k /= 2;
            i++;
        }
        elems[i].pb(k);
    }

    int best = 0;

    rep(i, 1, 64) {
        if (sz(elems[i]) > sz(elems[best])) {
            best = i;
        }
    }

    cout << n-sz(elems[best]) << '\n';

    rep(i, 0, 64) {
        if (i == best) continue;
        each(e, elems[i]) cout << (e << i) << ' ';
    }

    cout << endl;
}