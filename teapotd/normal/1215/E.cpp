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

ll invs[20][20];

void run() {
    int n; cin >> n;
    Vi elems(n);

    each(e, elems) {
        cin >> e;
        e--;
    }

    Vi cnt(20);
    each(e, elems) {
        rep(i, 0, 20) invs[i][e] += cnt[i];
        cnt[e]++;
    }

    vector<ll> dp(1<<20);

    rep(mask, 1, 1<<20) {
        dp[mask] = 1e18;
        for (int tmp = mask; tmp > 0; tmp &= (tmp-1)) {
            int c = __builtin_ctz(tmp);
            int rest = mask & ~(1<<c);
            ll alt = dp[rest];

            for (int kek = rest; kek > 0; kek &= (kek-1)) {
                int c2 = __builtin_ctz(kek);
                alt += invs[c][c2];
            }

            dp[mask] = min(dp[mask], alt);
        }
    }

    cout << dp.back() << '\n';
}