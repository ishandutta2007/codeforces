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

int dp[105][60005];

void run() {
    int n, r; cin >> n >> r;
    vector<Pii> up, down;

    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        if (b >= 0) {
            up.pb({a, b});
        } else {
            down.pb({a+b, -b});
        }
    }

    int ans = 0;
    sort(all(up));
    sort(all(down));

    each(e, up) {
        if (e.x > r) break;
        r += e.y;
        ans++;
    }

    rep(i, 0, sz(down)+1) rep(rate, 0, r+3) dp[i][rate] = -10000;
    dp[sz(down)][r] = 0;

    for (int i = sz(down)-1; i >= 0; i--) {
        rep(rate, 0, r+1) {
            dp[i][rate] = dp[i+1][rate];
            if (down[i].x <= rate) {
                int kek = rate + down[i].y;
                if (kek <= r) dp[i][rate] = max(dp[i][rate], dp[i+1][kek]+1);
            }
        }
    }

    int best = 0;
    rep(rate, 0, r+1) best = max(best, dp[0][rate]);
    cout << ans+best << endl;
}