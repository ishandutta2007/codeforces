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

struct Rect {
    int x1, y1, x2, y2;
};

Vi tAdd, tMax;
int len;

void add(int vb, int ve, int val, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return;
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

int query(int vb, int ve, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return 0;
    if (b >= vb && e <= ve) return tMax[i];
    int m = (b+e) / 2;
    int a = query(vb, ve, i*2, b, m);
    int c = query(vb, ve, i*2+1, m, e);
    return max(a, c) + tAdd[i];
}

Vi compressVec(vector<int*>& vec) {
    sort(all(vec), [](int* l, int* r) { return *l < *r; });
    Vi old;
    each(e, vec) {
        if (old.empty() || old.back() != *e) old.pb(*e);
        *e = sz(old)-1;
    }
    return old;
}

void run() {
    int n; cin >> n;
    vector<Rect> rects(n);
    vector<int*> toComp;

    each(r, rects) {
        cin >> r.x1 >> r.x2 >> r.y1 >> r.y2;
        toComp.pb(&r.x1);
        toComp.pb(&r.x2);
        toComp.pb(&r.y1);
        toComp.pb(&r.y2);
    }

    int maxC = sz(compressVec(toComp));
    for (len = 1; len < maxC; len *= 2);

    rep(rot, 0, 2) {
        vector<pair<Pii, int>> events;

        rep(i, 0, sz(rects)) {
            auto& r = rects[i];
            events.pb({{r.x1, 0}, i});
            events.pb({{r.x2, 1}, i});
        }

        sort(all(events));
        tAdd.assign(len*2, 0);
        tMax.assign(len*2, 0);

        each(e, events) {
            auto& r = rects[e.y];
            if (e.x.y == 0) {
                if (query(r.y1, r.y2+1) > 0) {
                    cout << "NO\n";
                    return;
                }
            } else {
                add(r.y1, r.y2+1, 1);
            }
        }

        each(r, rects) {
            swap(r.x1, r.y1);
            swap(r.x2, r.y2);
        }
    }

    cout << "YES\n";
}