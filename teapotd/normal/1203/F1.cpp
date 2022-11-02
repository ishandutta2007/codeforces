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

void answer(bool k) {
    cout << (k ? "YES" : "NO") << endl;
    exit(0);
}

void run() {
    int n, r; cin >> n >> r;
    vector<Pii> up, down;
    int totalDown = 0;

    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        if (b >= 0) {
            up.pb({a, b});
        } else {
            down.pb({a+b, -b});
            totalDown += -b;
        }
    }

    int ans = 0;
    sort(all(up));
    sort(all(down));

    each(e, up) {
        if (e.x > r) answer(0);
        r += e.y;
        ans++;
    }

    r -= totalDown;
    if (r < 0) answer(0);
    deb(r, down);

    each(e, down) {
        if (e.x > r) answer(0);
        r += e.y;
        ans++;
    }

    answer(1);
}