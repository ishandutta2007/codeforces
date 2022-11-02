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

constexpr ll MOD = 1e9+7;

ll solve(ll lim) {
    ll even = 0, odd = 0;
    ll cnt = 1;
    bool isOdd = 1;

    while (lim > 0) {
        ll amount = min(cnt, lim);
        if (isOdd) {
            odd += amount;
        } else {
            even += amount;
        }
        lim -= amount;
        cnt *= 2;
        isOdd = !isOdd;
    }

    even %= MOD;
    odd %= MOD;
    return (even*(even+1) + odd*(odd+1) - odd) % MOD;
}

void run() {
    ll l, r; cin >> l >> r;
    ll ans = (solve(r) - solve(l-1)) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}