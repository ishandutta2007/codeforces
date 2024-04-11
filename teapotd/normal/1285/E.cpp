#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

Vi tAdd, tLeft, tRight, tCnt;
int len;

void upd(int i) {
    if (tAdd[i] > 0) {
        tCnt[i] = tLeft[i] = tRight[i] = 1;
    } else if (i < len) {
        tCnt[i] = tCnt[i*2] + tCnt[i*2+1] - (tRight[i*2] && tLeft[i*2+1]);
        tLeft[i] = tLeft[i*2];
        tRight[i] = tRight[i*2+1];
    } else {
        tCnt[i] = tLeft[i] = tRight[i] = (tAdd[i] > 0);
    }
}

void add(int vb, int ve, int val, int i = 1, int b = 0, int e = len) {
    if (b >= ve || vb >= e) return;
    if (b >= vb && e <= ve) {
        tAdd[i] += val;
        assert(tAdd[i] >= 0);
    } else {
        int m = (b+e) / 2;
        add(vb, ve, val, i*2, b, m);
        add(vb, ve, val, i*2+1, m, e);
    }
    upd(i);
}

Vi compressVec(vector<int*>& vec) {
    sort(all(vec),
        [](int* l, int* r) { return *l < *r; });
    Vi old;
    each(e, vec) {
        if (old.empty() || old.back() != *e)
            old.pb(*e);
        *e = sz(old)-1;
    }
    return old;
}

void solve() {
    int n; cin >> n;
    vector<Pii> elems(n);
    vector<int*> kek;

    each(e, elems) {
        cin >> e.x >> e.y;
        e.x *= 2;
        e.y *= 2;
        e.y++;
        kek.pb(&e.x);
        kek.pb(&e.y);
    }

    int maxCoord = sz(compressVec(kek));
    for (len = 1; len < maxCoord; len *= 2);

    tAdd.assign(len*2, 0);
    tLeft.assign(len*2, 0);
    tRight.assign(len*2, 0);
    tCnt.assign(len*2, 0);

    each(e, elems) {
        add(e.x, e.y, 1);
    }

    int ans = 0;

    each(e, elems) {
        add(e.x, e.y, -1);
        ans = max(ans, tCnt[1]);
        add(e.x, e.y, 1);
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}