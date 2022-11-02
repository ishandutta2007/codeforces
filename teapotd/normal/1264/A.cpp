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

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        Vi cnt;
        int last = -1;

        rep(i, 0, n) {
            int p; cin >> p;
            if (last != p) cnt.pb(0);
            cnt.back()++;
            last = p;
        }

        int pref = 0;

        rep(i, 0, sz(cnt)) {
            pref += cnt[i];
            if (pref > n/2) {
                cnt.resize(i);
                break;
            }
        }

        if (sz(cnt) < 3) {
            cout << "0 0 0\n";
            continue;
        }

        int g = cnt[0], s = 0, b = 0;
        int i = 1;

        for (; i < sz(cnt) && s <= g; i++) {
            s += cnt[i];
        }

        for (; i < sz(cnt); i++) {
            b += cnt[i];
        }

        if (g <= 0 || s <= 0 || b <= 0 || g >= s || g >= b) {
            cout << "0 0 0\n";
            continue;
        }

        cout << g << ' ' << s << ' ' << b << '\n';
    }
}