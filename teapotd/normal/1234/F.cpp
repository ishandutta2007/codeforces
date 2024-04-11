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

int seen[1<<20], sos[1<<20];

void run() {
    string s; cin >> s;
    seen[0] = 1;

    rep(i, 0, sz(s)) {
        int mask = 0;
        rep(j, i, sz(s)) {
            int bit = s[j] - 'a';
            if ((mask >> bit) & 1) break;
            mask |= 1 << bit;
            seen[mask] = 1;
        }
    }

    rep(i, 0, 1<<20) {
        if (seen[i]) sos[i] = __builtin_popcount(i);
    }

    rep(i, 0, 20) rep(m, 0, 1<<20) {
        if ((m >> i) & 1) {
            sos[m] = max(sos[m], sos[m^(1<<i)]);
        }
    }

    int ans = 0;

    rep(i, 0, 1<<20) {
        ans = max(ans, sos[i] + sos[i ^ ((1<<20)-1)]);
    }

    cout << ans << endl;
}