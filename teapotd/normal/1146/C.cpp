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
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        ll ans = 0;

        rep(i, 0, 9) {
            Vi s1, s2;

            rep(j, 0, n) {
                if ((j >> i) & 1) s1.pb(j+1);
                else s2.pb(j+1);
            }

            if (!s1.empty() && !s2.empty()) {
                cout << sz(s1) << ' ' << sz(s2) << ' ';
                each(j, s1) cout << j << ' ';
                each(j, s2) cout << j << ' ';
                cout << endl;

                ll d; cin >> d;
                ans = max(ans, d);
            }
        }

        cout << -1 << ' ' << ans << endl;
    }
}