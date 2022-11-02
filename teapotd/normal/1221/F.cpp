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

constexpr ll INF = 1e17;

struct Point {
    int x, y, c;
};

int n;
vector<Point> elems, elemsOrig;
Vi decomp;

vector<ll> tAdd;
vector<pair<ll, int>> tMax;
int len;

void add(int vb, int ve, ll val, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return;

    if (b >= vb && e <= ve) {
        tAdd[i] += val;
        tMax[i].x += val;
        return;
    }

    int m = (b+e) / 2;
    add(vb, ve, val, i*2, b, m);
    add(vb, ve, val, i*2+1, m, e);
    tMax[i] = max(tMax[i*2], tMax[i*2+1]);
    tMax[i].x += tAdd[i];
}

Vi compressVec(vector<int*>& vec) {
    sort(all(vec), [](int* l, int* r) { return *l < *r; });
    Vi orig;
    each(e, vec) {
        if (orig.empty() || orig.back() != *e) {
            orig.pb(*e);
        }
        *e = sz(orig)-1;
    }
    return orig;
}

void check(int start, int end, ll ans) {
    ll alt = start-end;
    each(e, elemsOrig) {
        if (e.x >= start && e.x <= end && e.y >= start && e.y <= end) {
            alt += e.c;
        }
    }
    assert(alt == ans);
}

void run() {
    cin >> n;
    elems.resize(n);

    vector<int*> tmp;

    each(e, elems) {
        cin >> e.x >> e.y >> e.c;
    }

    elemsOrig = elems;

    each(e, elems) {
        if (e.x > e.y) swap(e.x, e.y);
        tmp.pb(&e.x);
        tmp.pb(&e.y);
    }

    decomp = compressVec(tmp);
    sort(all(elems), [](Point l, Point r) { return l.x < r.x; });

    for (len = 1; len < sz(decomp); len *= 2);
    tAdd.resize(len*2);
    tMax.resize(len*2);

    rep(i, 0, len) {
        tAdd[i+len] = -INF;
        tMax[i+len] = {tAdd[i+len], i};
    }

    for (int i = len-1; i > 0; i--) {
        tMax[i] = max(tMax[i*2], tMax[i*2+1]);
    }

    ll best = 0;
    int bestStart = 1e9+5, bestEnd = 1e9+5;
    int j = n-1;

    for (int i = sz(decomp)-1; i >= 0; i--) {
        while (j >= 0 && elems[j].x >= i) {
            add(elems[j].y, sz(decomp), elems[j].c);
            j--;
        }

        add(i, i+1, INF-decomp[i]);

        ll alt = tMax[1].x + decomp[i];

        if (alt > best) {
            best = alt;
            bestStart = i;
            bestEnd = tMax[1].y;
        }
    }

    if (bestStart < sz(decomp)) {
        bestStart = decomp[bestStart];
        bestEnd = decomp[bestEnd];
    }
    cout << best << '\n';
    cout << bestStart << ' ' << bestStart << ' ' << bestEnd << ' ' << bestEnd << '\n';
    cout << flush;

#ifdef LOC
    check(bestStart, bestEnd, best);
#endif
}