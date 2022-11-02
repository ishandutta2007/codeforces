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

constexpr int INF = 1e9;

struct Group {
    vector<pair<Pii, int>> add, del;
};

int n, m, curVer, comps;
Vi ver, par;

int id(int i, int j) {
    return i*m + j;
}

int find(int i) {
    return par[i] != -1 ? par[i] = find(par[i]) : i;
}

void reset() {
    curVer++;
    comps = 0;
}

bool join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) return 0;
    par[i] = j;
    return 1;
}

void enable(int x, int y) {
    int i = id(x, y);
    if (ver[i] == curVer) return;

    ver[i] = curVer;
    par[i] = -1;
    comps++;

    rep(dx, -1, 2) rep(dy, -1, 2) {
        if (abs(dx)+abs(dy) != 1) continue;
        if (x+dx < 0 || x+dx >= n || y+dy < 0 || y+dy >= m) continue;
        int j = id(x+dx, y+dy);
        if (ver[j] == curVer) {
            comps -= join(i, j);
        }
    }
}

void run() {
    int q;
    cin >> n >> m >> q;

    Vi col(n*m);
    vector<Group> groups(1);

    rep(i, 0, n) rep(j, 0, m) {
        groups[0].add.pb({ {i, j}, 0 });
    }

    rep(i, 1, q+1) {
        int x, y, c; cin >> x >> y >> c;
        x--; y--;

        int k = id(x, y);
        if (col[k] == c) continue;
        assert(col[k] < c);

        if (sz(groups) <= c) {
            groups.resize(c+1);
        }

        groups[col[k]].del.pb({ {x, y}, i });
        groups[c].add.pb({ {x, y}, i });
        col[k] = c;
    }

    rep(i, 0, n) rep(j, 0, m) {
        int k = id(i, j);
        groups[col[k]].del.pb({ {i, j}, q+1 });
    }

    Vi pref(q+2);
    ver.resize(n*m);
    par.resize(n*m);

    each(g, groups) {
        int last = 0;
        reset();

        each(p, g.add) {
            enable(p.x.x, p.x.y);
            pref[p.y] += comps-last;
            last = comps;
        }

        last = 0;
        reset();

        for (int i = sz(g.del)-1; i >= 0; i--) {
            auto p = g.del[i];
            enable(p.x.x, p.x.y);
            pref[p.y] -= comps-last;
            last = comps;
        }
    }

    rep(i, 1, sz(pref)) {
        pref[i] += pref[i-1];
    }

    rep(i, 1, q+1) {
        cout << pref[i] << '\n';
    }
}