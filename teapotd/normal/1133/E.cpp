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
    int n, k; cin >> n >> k;
    Vi elems(n);
    each(e, elems) cin >> e;
    sort(all(elems));

    Vi lens(n+1);
    int s = 0;

    rep(i, 0, n) {
        while (s < n && elems[s]-elems[i] <= 5) s++;
        lens[i] = s-i;
    }

    Vi dp(n+1);
    for (int i = n-1; i >= 0; i--) {
        dp[i] = max(dp[i+1], lens[i]);
    }

    rep(i, 1, k) {
        rep(j, 0, n) {
            dp[j] = max(dp[j], lens[j]+dp[j+lens[j]]);
        }
        for (int j = n-1; j >= 0; j--) {
            dp[j] = max(dp[j+1], dp[j]);
        }
    }

    cout << dp[0] << endl;
}