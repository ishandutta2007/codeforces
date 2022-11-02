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

constexpr int MOD = 998244353;

void run() {
    int n; cin >> n;
    vector<Pii> elems(n);
    each(e, elems) cin >> e.x >> e.y;
    sort(all(elems));

    vector<ll> fact(n+1, 1);
    rep(i, 2, n+1) fact[i] = fact[i-1]*i % MOD;

    ll ans = fact[n];
    ll sub = 1, cur = 0;
    Pii last = {-1, -1};

    each(e, elems) {
        if (last.y > e.y) {
            sub = 0;
            break;
        }
        if (e != last) {
            sub = sub*fact[cur] % MOD;
            cur = 0;
            last = e;
        }
        cur++;
    }

    sub = sub*fact[cur] % MOD;
    ans = (ans+sub) % MOD;

    auto dim = [&](Vi& vec) {
        sort(all(vec));
        ll kek = -1;
        sub = 1, cur = 0;
        each(e, vec) {
            if (e != kek) {
                sub = sub*fact[cur] % MOD;
                cur = 0;
                kek = e;
            }
            cur++;
        }
        sub = sub*fact[cur] % MOD;
        ans = (ans-sub+MOD) % MOD;
    };

    Vi a, b;
    each(e, elems) {
        a.pb(e.x);
        b.pb(e.y);
    }

    dim(a);
    dim(b);

    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}