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

bool solve() {
    int a, b; cin >> a >> b;
    string s; cin >> s;

    Vi stacks;

    rep(i, 0, sz(s)) {
        if (s[i] == '.' && (i == 0 || s[i-1] == 'X')) {
            int j = i;
            while (j < sz(s) && s[j] == '.') j++;
            stacks.pb(j-i);
        }
    }

    int oneShot = 0;
    Vi high;

    each(k, stacks) if (k >= b) {
        if (k < a) return 0;
        if (k < b*2) oneShot++;
        else high.pb(k);
    }

    if (sz(high) >= 2) return 0;
    if (sz(high) == 0) return oneShot%2;

    int h = high[0];

    rep(i, 0, h-a+1) {
        int j = h-a-i;
        int opt = oneShot;

        if (i >= b) {
            if (i < a || i >= b*2) continue;
            opt++;
        }

        if (j >= b) {
            if (j < a || j >= b*2) continue;
            opt++;
        }

        if (opt%2 == 0) return 1;
    }

    return 0;
}

void run() {
    int q; cin >> q;
    while (q--) cout << (solve() ? "YES\n" : "NO\n");
}