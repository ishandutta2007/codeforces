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
    vector<ll> algs(n);
    Vi skill(n);
    each(a, algs) cin >> a;
    each(s, skill) cin >> s;

    Vi deg(n);
    vector<bool> used(n, 1);
    int nUsed = n;

    auto better = [&](int i, int j) {
        return (algs[i] & ~algs[j]) != 0;
    };

    rep(i, 0, n) {
        rep(j, 0, n) if (i != j) {
            deg[i] += better(i, j);
        }
    }

    while (nUsed >= 2) {
        bool ok = 1;
        rep(i, 0, n) if (used[i]) {
            if (deg[i] < nUsed-1) continue;
            used[i] = 0;
            ok = 0;
            nUsed--;
            rep(j, 0, n) if (i != j) {
                deg[j] -= better(j, i);
            }
            break;
        }
        if (ok) break;
    }

    if (nUsed <= 1) {
        cout << 0 << endl;
        return;
    }

    ll sum = 0;
    rep(i, 0, n) if (used[i]) sum += skill[i];
    cout << sum << endl;
}