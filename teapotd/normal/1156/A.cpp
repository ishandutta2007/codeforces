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

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    int ans = 0;

    rep(i, 1, n) {
        int a = elems[i], b = elems[i-1];

        if (a == 1 && b == 2) {
            ans += 3;
        } else if (a == 1 && b == 3) {
            ans += 4;
        } else if (a == 2 && b == 1) {
            ans += 3;
        } else if (a == 2 && b == 3) {
            cout << "Infinite\n";
            return;
        } else if (a == 3 && b == 1) {
            ans += 4;
        } else if (a == 3 && b == 2) {
            cout << "Infinite\n";
            return;
        }
    }

    rep(i, 2, n) {
        if (elems[i-2] == 3 && elems[i-1] == 1 && elems[i] == 2) {
            ans--;
        }
    }

    cout << "Finite\n" << ans << endl;
}