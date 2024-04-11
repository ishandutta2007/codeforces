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
    int n; cin >> n;
    Vi elems;

    rep(i, 0, n) {
        int k; cin >> k;
        if (k == 4) elems.pb(0);
        else if (k == 8) elems.pb(1);
        else if (k == 15) elems.pb(2);
        else if (k == 16) elems.pb(3);
        else if (k == 23) elems.pb(4);
        else if (k == 42) elems.pb(5);
    }

    n = sz(elems);
    Vi pos[6];
    for (int i = n-1; i >= 0; i--) pos[elems[i]].pb(i);

    int ans = 0;

    while (true) {
        int cur = 0;
        bool ok = 1;

        rep(i, 0, 6) {
            while (!pos[i].empty() && pos[i].back() < cur) {
                pos[i].pop_back();
            }
            if (pos[i].empty()) {
                ok = 0;
                break;
            }
            cur = pos[i].back();
            pos[i].pop_back();
        }

        if (!ok) break;
        ans += 6;
    }

    cout << n-ans << endl;
}