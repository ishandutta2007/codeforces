#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize")
#pragma GCC target("popcnt,mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,tune=native")
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

constexpr int MAX_N = 2048;

vector<bitset<MAX_N>> rows, prefs;
Vi cnt;
set<Pii> sorted;
stack<Pii> good;

bool isGood(int a, int b) {
    return cnt[a] <= cnt[b] && (rows[a]&rows[b]) != rows[a];
}

void consider(set<Pii>::iterator it) {
    if (it != sorted.begin() && it != sorted.end()) {
        int a = prev(it)->y, b = it->y;
        if (isGood(a, b)) good.push({a, b});
    }
}

void flip(int r, int begin, int end) {
    consider(sorted.erase(sorted.find({cnt[r], r})));

    rows[r] ^= prefs[begin];
    rows[r] ^= prefs[end];
    cnt[r] = int(rows[r].count());

    auto it = sorted.insert({cnt[r], r});
    consider(it.x);
    consider(next(it.x));
}

void handle(int r, int begin, int end) {
    flip(r, begin, end);

    while (!good.empty()) {
        Pii p = good.top();
        if (isGood(p.x, p.y)) break;
        good.pop();
    }

    if (good.empty()) {
        cout << "-1\n";
        return;
    }

    Pii p = good.top();
    auto a = rows[p.x] & ~rows[p.y];
    auto b = ~rows[p.x] & rows[p.y];

    int x1 = p.x+1, x2 = p.y+1;
    int y1 = int(a._Find_first()) + 1;
    int y2 = int(b._Find_first()) + 1;

    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
}

void run() {
    int n, m, q; cin >> n >> m >> q;

    prefs.resize(m+1);
    rows.resize(n);
    cnt.resize(n);

    rep(i, 1, m+1) {
        prefs[i] = prefs[i-1];
        prefs[i].set(i-1);
    }

    rep(i, 0, n) {
        sorted.insert({0, i});
    }

    rep(i, 0, q) {
        int a, l, r; cin >> a >> l >> r;
        handle(a-1, l-1, r);
    }
}