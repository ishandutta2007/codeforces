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

void handle() {
    int n; cin >> n;
    string elems; cin >> elems;

    Pii split = {100, 100};
    int small = 100;

    for (int i = n-1; i >= 0; i--) {
        int d = elems[i]-'0';
        if (d > small) {
            split = min(split, make_pair(d, 100-i));
        }
        small = min(small, d);
    }

    string ans;
    Vi l, r;

    rep(i, 0, n) {
        int d = elems[i]-'0';
        if (d > split.x || (d == split.x && i <= 100-split.y)) {
            ans.pb('2');
            r.pb(d);
        } else {
            ans.pb('1');
            l.pb(d);
        }
    }

    int last = -1;
    bool bad = 0;

    each(e, l) {
        if (e < last) bad = 1;
        last = e;
    }
    each(e, r) {
        if (e < last) bad = 1;
        last = e;
    }

    deb(bad, split);

    if (bad) {
        cout << "-\n";
    } else {
        cout << ans << '\n';
    }
}

void run() {
    int t; cin >> t;
    while (t--) handle();
}