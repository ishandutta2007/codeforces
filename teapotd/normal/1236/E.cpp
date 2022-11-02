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

constexpr int OFF = 3e5;

int n, m;
Vi elems, dpDown, dpUp;
vector<Vi> down, up;

int getDown(int i) {
    if (dpDown[i] == -1) {
        int e = elems[i];
        int diag = e-i+OFF-1;
        dpDown[i] = 0;
        if (diag >= 0) {
            auto it = lower_bound(all(down[diag]), i);
            if (it != down[diag].end()) {
                dpDown[i] = getDown(*it)+1;
            }
        }
    }
    return dpDown[i];
}

int getUp(int i) {
    if (dpUp[i] == -1) {
        int e = elems[i];
        int diag = i+e+1;
        dpUp[i] = 0;
        auto it = lower_bound(all(up[diag]), i);
        if (it != up[diag].end()) {
            dpUp[i] = getUp(*it)+1;
        }
    }
    return dpUp[i];
}

void run() {
    cin >> n >> m;
    elems.resize(m);
    each(e, elems) cin >> e;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    down.resize(6e5);
    up.resize(6e5);

    rep(i, 0, m) {
        int e = elems[i];
        down[e-i+OFF].pb(i);
        up[i+e].pb(i);
    }

    dpDown.resize(m, -1);
    dpUp.resize(m, -1);

    ll ans = 0;

    rep(i, 1, n+1) {
        int begin = i-m-1, end = i+m+1;

        if (!up[i-1].empty()) {
            begin += getUp(up[i-1][0])+1;
            deb(i, up[i-1]);
        }
        if (!down[i+OFF+1].empty()) {
            end -= getDown(down[i+OFF+1][0])+1;
            deb(i, down[i+OFF+1]);
        }

        if (begin > end) continue;
        begin = max(begin, 1);
        end = min(end, n);
        int add = end-begin+1;
        ans += max(add, 0);
        deb(i, add);
    }

    cout << ans << endl;
}