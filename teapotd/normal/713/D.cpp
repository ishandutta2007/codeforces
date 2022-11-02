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

#define left left__

struct RMQ {
    using T = int;
    static constexpr T ID = INT_MIN;
    T f(T a, T b)  { return max(a, b); }

    vector<T> buf;
    int stride;

    T* row(int lvl) { return &buf[lvl*stride]; }
    T& at(int lvl, int i) { return buf[lvl*stride+i]; }

    void init(T* vec, int len) {
        stride = len;
        buf.resize(len*12);
        rep(i, 0, len) at(0, i) = vec[i];
        int lvl = 0;
        for (int h = 1; h <= len; h *= 2) {
            lvl++;
            auto prev = row(lvl-1);
            rep(i, 0, len-h*2+1) at(lvl, i) = f(prev[i], prev[i+h]);
        }
    }

    T query(int b, int e) {
        if (b >= e) return ID;
        int k = 31 - __builtin_clz(e-b);
        return f(at(k, b), at(k, e - (1<<k)));
    }
};

constexpr int MX = 1024;

int n, m;
bool mat[MX][MX];
int left[MX][MX], top[MX][MX], sqr[MX][MX];

vector<RMQ> tree;
int len;

int query(int vb, int ve, int vb2, int ve2, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return INT_MIN;
    if (b >= vb && e <= ve) return tree[i].query(vb2, ve2);
    int mid = (b+e) / 2;
    return max(query(vb, ve, vb2, ve2, i*2, b, mid), query(vb, ve, vb2, ve2, i*2+1, mid, e));
}

void run() {
    cin >> n >> m;

    rep(i, 1, n+1) rep(j, 1, m+1) {
        cin >> mat[i][j];
        if (mat[i][j]) {
            left[i][j] = left[i-1][j]+1;
            top[i][j] = top[i][j-1]+1;
            sqr[i][j] = min(min(left[i][j], top[i][j]), sqr[i-1][j-1]+1);
        }
    }

    for (len = 1; len < n; len *= 2);
    tree.resize(len*2);

    rep(i, 0, n) {
        tree[len+i].init(&sqr[i+1][1], m);
    }

    for (int i = len-1; i > 0; i--) {
        tree[i] = tree[i*2];
        if (!tree[i*2+1].buf.empty()) {
            rep(j, 0, sz(tree[i].buf)) {
                tree[i].buf[j] = max(tree[i].buf[j], tree[i*2+1].buf[j]);
            }
        }
    }

    int t; cin >> t;

    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;

        int begin = 0, end = min(x2-x1, y2-y1)+1;

        while (begin+1 < end) {
            int mid = (begin+end) / 2;
            int k = query(x1+mid-1, x2, y1+mid-1, y2);
            if (k >= mid) {
                begin = mid;
            } else {
                end = mid;
            }
        }

        cout << begin << '\n';
    }
}