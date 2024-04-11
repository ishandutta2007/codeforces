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
    // a for 0,3,6
    // b for 1,5
    // c for 2,4
    ll a, b, c;
    cin >> a >> b >> c;

    ll full = min(min(a/3, b/2), c/2);
    ll ans = full*7;

    rep(i, 0, 7) {
        constexpr int sched[7] = {0,1,2,0,2,1,0};
        ll tmp[3] = {a-full*3,b-full*2,c-full*2};
        ll more = 0;

        rep(j, 0, 7) {
            int k = sched[(i+j) % 7];
            if (--tmp[k] < 0) {
                break;
            }
            more++;
        }

        ans = max(ans, full*7+more);
    }

    cout << ans << endl;
}