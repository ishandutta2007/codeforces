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
    int t; cin >> t;

    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        Vi hei(n);
        each(h, hei) cin >> h;

        bool ok = 1;
        ll has = m;
        ll at = hei[0];

        rep(i, 1, n) {
            ll dst = max(hei[i]-k, 0);
            deb(dst, has, at, hei);
            if (dst-at > has) {
                ok = 0;
                break;
            }
            has += at-dst;
            at = hei[i];
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}