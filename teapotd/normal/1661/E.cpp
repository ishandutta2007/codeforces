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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

struct Tag {
    array<int, 3> L = {}, R = {};
    int cnt = 0;
    DBP(L, R, cnt);
};

vector<Tag> tree;
int len;

Tag merge(Tag l, Tag r) {
    int tot = l.cnt + r.cnt;
    each(k, r.L) if (k) k += 8;
    each(k, r.R) if (k) k += 8;

    rep(i, 0, 3) {
        int old = r.L[i], neu = l.R[i];
        if (old && neu && old != neu) {
            each(k, l.L) if (k == old) k = neu;
            each(k, l.R) if (k == old) k = neu;
            each(k, r.L) if (k == old) k = neu;
            each(k, r.R) if (k == old) k = neu;
            tot--;
        }
    }

    Tag ret = {l.L, r.R, tot};

    int has[16] = {};
    each(k, ret.L) has[k] = 1;
    each(k, ret.R) has[k] = 1;
    has[0] = 0;
    rep(i, 2, 16) has[i] += has[i-1];

    each(k, ret.L) k = has[k];
    each(k, ret.R) k = has[k];
    //deb(l, r, ret);
    return ret;
}

Tag query(int vb, int ve, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return {};
    if (b >= vb && e <= ve) return tree[i];
    int m = (b+e) / 2;
    return merge(query(vb, ve, i*2, b, m), query(vb, ve, i*2+1, m, e));
}

void run() {
    int n; cin >> n;
    string rows[3];
    each(e, rows) cin >> e;

    for (len = 1; len < n; len *= 2);
    tree.resize(len*2);

    rep(i, 0, n) {
        auto &v = tree[len+i];
        bool a = rows[0][i] == '1', b = rows[1][i] == '1', c = rows[2][i] == '1';
        if (!a && !b && !c) {
            v.L = v.R = {0, 0, 0};
            v.cnt = 0;
        } else if (a && !b && !c) {
            v.L = v.R = {1, 0, 0};
            v.cnt = 1;
        } else if (!a && b && !c) {
            v.L = v.R = {0, 1, 0};
            v.cnt = 1;
        } else if (a && b && !c) {
            v.L = v.R = {1, 1, 0};
            v.cnt = 1;
        } else if (!a && !b && c) {
            v.L = v.R = {0, 0, 1};
            v.cnt = 1;
        } else if (a && !b && c) {
            v.L = v.R = {1, 0, 2};
            v.cnt = 2;
        } else if (!a && b && c) {
            v.L = v.R = {0, 1, 1};
            v.cnt = 1;
        } else if (a && b && c) {
            v.L = v.R = {1, 1, 1};
            v.cnt = 1;
        } else {
            assert(0);
        }
    }

    for (int i = len-1; i > 0; i--) {
        tree[i] = merge(tree[i*2], tree[i*2+1]);
    }

    deb(tree);

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << query(l-1, r).cnt << '\n';
    }
}