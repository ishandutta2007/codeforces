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

using ull = unsigned long long;

struct SegTree {
    vector<ull> tMin, tMax, tMinTag, tMult, tSum;
    int len;

    SegTree(int n = 0) {
        for (len = 1; len < n; len *= 2);
        tMin.resize(len*2, INT64_MAX);
        tMax.resize(len*2, INT64_MAX);
        tMinTag.resize(len*2, INT64_MAX);
        tMult.resize(len*2, 0);
        tSum.resize(len*2, 0);
    }

    void update(int i) {
        assert(tMinTag[i] == INT64_MAX);
        tMin[i] = min(tMin[i*2], tMin[i*2+1]);
        tMax[i] = max(tMax[i*2], tMax[i*2+1]);
        tMult[i] = tMult[i*2] + tMult[i*2+1];
        tSum[i] = tSum[i*2] + tSum[i*2+1];
    }

    void push(int i) {
        if (tMinTag[i] == INT64_MAX) return;
        rep(j, 0, 2) {
            assert(tMin[i*2+j] == tMax[i*2+j]);
            tMinTag[i*2+j] = min(tMinTag[i*2+j], tMinTag[i]);
            tMin[i*2+j] = tMax[i*2+j] = min(tMin[i*2+j], tMinTag[i*2+j]);
            tSum[i*2+j] = tMult[i*2+j] * tMin[i*2+j];
        }
        tMinTag[i] = INT64_MAX;
    }

    void setMult(int pos, ull val, int i = 1, int b = 0, int e = -1) {
        if (e < 0) e = len;

        if (i >= len) {
            tMult[i] = val;
            tSum[i] = tMult[i] * tMin[i];
            return;
        }

        int m = (b+e) / 2;
        push(i);
        if (pos < m) {
            setMult(pos, val, i*2, b, m);
        } else {
            setMult(pos, val, i*2+1, m, e);
        }
        update(i);
    }

    void setMin(int vb, int ve, ull val, int i = 1, int b = 0, int e = -1) {
        if (e < 0) e = len;
        if (b >= ve || vb >= e || val >= tMax[i]) return;

        if (b >= vb && e <= ve && tMin[i] == tMax[i]) {
            tMinTag[i] = min(tMinTag[i], val);
            tMin[i] = tMax[i] = min(tMin[i], tMinTag[i]);
            tSum[i] = tMult[i] * tMin[i];
            return;
        }

        int m = (b+e) / 2;
        push(i);
        setMin(vb, ve, val, i*2, b, m);
        setMin(vb, ve, val, i*2+1, m, e);
        update(i);
    }
};

SegTree tree;
Vi str, ps;
vector<Vi> del;
int len = 0;
ull ans = 0;

void add(int c, int w) {
    str[len++] = c;
    tree.setMin(0, len, w);

    if (len == 1) {
        ps[1] = 0;
        tree.setMult(0, 1);
        ans += tree.tSum[1];
        return;
    }

    int k = ps[len-1];

    while (k >= 0 && str[k] != c) {
        del[len].pb(k+1);
        k = ps[k];
    }

    ps[len] = k+1;
    each(d, del[ps[len]]) del[len].pb(d);

    if (str[len-1] == str[0]) {
        tree.setMult(len-1, 1);
    }

    each(d, del[len]) {
        tree.setMult(len-d, 0);
    }

    ans += tree.tSum[1];
}

void run() {
    int n; cin >> n;
    str.resize(n);
    ps.resize(n+1, -1);
    del.resize(n+1);
    tree = {n};

    rep(i, 0, n) {
        char rawC;
        int w;
        cin >> rawC >> w;

        int c = int(((rawC-'a') + ans) % 26);
        w ^= int(ans & ((1<<30)-1));

        add(c, w);
        cout << ans << '\n';
    }
}