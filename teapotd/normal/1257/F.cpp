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

constexpr int HALF = 1<<15;
constexpr int MOD = 1e9+7;
constexpr int BASE = 37;

Vi elems;

void check(int mask) {
    int k = __builtin_popcount(elems[0] ^ mask);

    rep(i, 1, sz(elems)) {
        int alt = __builtin_popcount(elems[i] ^ mask);
        if (alt != k) return;
    }
    
    cout << mask << endl;
    exit(0);
}

void run() {
    int n; cin >> n;
    elems.resize(n);
    each(e, elems) cin >> e;

    map<ll, Vi> masks;

    ll single = 0;
    rep(i, 0, n) {
        single = (single*BASE + 1) % MOD;
    }

    for (int mask = 0; mask < HALF; mask++) {
        ll hash1 = 0;
        each(e,  elems) {
            int v1 = __builtin_popcount((e & (HALF-1)) ^ mask);
            hash1 = (hash1*BASE + v1) % MOD;
        }
        masks[hash1].pb(mask);
    }

    for (int mask = 0; mask < HALF; mask++) {
        ll hash2 = 0;
        each(e,  elems) {
            int v2 = __builtin_popcount((e >> 15) ^ mask);
            hash2 = (hash2*BASE + v2) % MOD;
        }

        rep(k, 0, 31) {
            ll rest = (single*k - hash2) % MOD;
            if (rest < 0) rest += MOD;

            if (masks.count(rest)) {
                each(m, masks[rest]) {
                    int full = (mask << 15) | m;
                    check(full);
                }
            }
        }
    }

    cout << -1 << endl;
}