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

Vi tAdd, tMax;
int len;

void add(int vb, int ve, int val, int i = 1, int b = 0, int e = len) {
    if (b >= ve || vb >= e) return;

    if (b >= vb && e <= ve) {
        tAdd[i] += val;
        tMax[i] += val;
        return;
    }

    int m = (b+e) / 2;
    add(vb, ve, val, i*2, b, m);
    add(vb, ve, val, i*2+1, m, e);
    tMax[i] = max(tMax[i*2], tMax[i*2+1]) + tAdd[i];
}

int findOne(int i = 1, int b = 0, int e = len) {
    if (i >= len) return b;
    if (tMax[i] < 1) return -1;

    int m = (b+e) / 2;

    rep(j, 0, 2) {
        tAdd[i*2+j] += tAdd[i];
        tMax[i*2+j] += tAdd[i];
    }
    tAdd[i] = 0;

    if (tMax[i*2+1] >= 1) {
        return findOne(i*2+1, m, e);
    } else {
        return findOne(i*2, b, m);
    }
}

void run() {
    int n, m; cin >> n >> m;

    len = 1<<20;
    tAdd.resize(len*2);
    tMax.resize(len*2);

    Vi plus(n), minus(m);

    each(p, plus) {
        cin >> p;
        add(0, p+1, 1);
    }

    each(p, minus) {
        cin >> p;
        add(0, p+1, -1);
    }

    int q; cin >> q;

    rep(j, 0, q) {
        int t, i, x; cin >> t >> i >> x;
        i--;

        if (t == 1) {
            add(0, plus[i]+1, -1);
            plus[i] = x;
            add(0, plus[i]+1, 1);
        } else {
            add(0, minus[i]+1, 1);
            minus[i] = x;
            add(0, minus[i]+1, -1);
        }

        cout << findOne() << '\n';
    }
}