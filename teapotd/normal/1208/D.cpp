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

vector<ll> tAdd;
vector<pair<ll, int>> tMin;
int len;

void upd(int i) {
    tMin[i] = min(tMin[i*2], tMin[i*2+1]);
    tMin[i].x += tAdd[i];
}

void add(int vb, int ve, ll val, int i = 1, int b = 0, int e = len) {
    if (b >= ve || vb >= e) return;

    if (b >= vb && e <= ve) {
        tAdd[i] += val;
        tMin[i].x += val;
        return;
    }

    int m = (b+e) / 2;
    add(vb, ve, val, i*2, b, m);
    add(vb, ve, val, i*2+1, m, e);
    upd(i);
}

void run() {
    int n; cin >> n;

    for (len = 1; len < n; len *= 2);
    tAdd.resize(len*2, 0);
    tMin.resize(len*2, {1e18, 1e9});

    rep(i, 0, n) {
        cin >> tAdd[i+len];
        tMin[i+len] = {tAdd[i+len], -i};
    }

    for (int i = len-1; i > 0; i--) {
        upd(i);
    }

    Vi perm(n);

    rep(i, 1, n+1) {
        assert(tMin[1].x == 0);
        int pos = -tMin[1].y;
        perm[pos] = i;
        add(pos, pos+1, 1e18);
        add(pos+1, n, -i);
    }

    each(p, perm) cout << p << ' ';
    cout << endl;
}