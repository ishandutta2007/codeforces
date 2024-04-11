#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 998244353
#define maxn 100010

int i, i1, j, k, k1, t, n, m[2], res, flag[10], a, b;
vector<array<int, 2>> el[2], rs;
set<array<int, 2>> cc[2];

struct dsu {
    int ty;
    vector<int> pr, sz;

    dsu(int x): pr({}) {
        int i;
        ty = x;
        pr.resize(maxn); sz.resize(maxn);
        for (i = 0; i < maxn; i++) {
            pr[i] = i; sz[i] = 1;
        }
    }

    int find(int x) {
        if (pr[x] == x) return x;
        return pr[x] = find(pr[x]);
    }

    bool same(int a, int b) {
        return (find(a) == find(b));
    }

    void merge(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        cc[ty].erase({sz[a], a}); cc[ty].erase({sz[b], b});
        pr[b] = a; sz[a] += sz[b];
        cc[ty].insert({sz[a], a});
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    dsu ds0 = dsu(0); dsu ds1 = dsu(1);

    cin >> n >> m[0] >> m[1];
    for (i = 1; i <= m[0]; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        el[0].pb({a, b});
    }
    for (i = 1; i <= m[1]; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        el[1].pb({a, b});
    }

    if (m[0] < m[1]) {
        swap(m[0], m[1]); swap(el[0], el[1]);
    }

    // sort(el[0].begin(), el[0].end()); sort(el[1].begin(), el[1].end());

    for (i = 1; i <= n; i++) {
        cc[0].insert({1, i}); cc[1].insert({1, i});
    }

    for (auto u : el[0]) {
        if (ds0.same(u[0], u[1])) continue;
        ds0.merge(u[0], u[1]);
    }

    for (auto u : el[1]) {
        if (ds1.same(u[0], u[1])) continue;
        ds1.merge(u[0], u[1]);
    }

    for (i = 1; i <= n - m[0] - 1; i++) {
        /* cout << "dbg" << nl;
        for (auto u : cc) cout << u[0] _ u[1] _ u[2] << nl; */

        array<int, 2> x = (*cc[0].begin());
        array<int, 2> y = (*cc[1].begin());
        if (x < y) {
            a = x[1]; k = 1;
        } else {
            a = y[1]; k = 0;
        }

        auto it = cc[k].begin();
        b = a;
        while (ds0.same(a, b) || ds1.same(a, b)) {
            if (it == cc[k].end()) b = (b % n) + 1;
            else b = (*it)[1], it++;
        }

        ds0.merge(a, b); ds1.merge(a, b); rs.pb({a, b});
    }

    cout << rs.size() << nl;
    for (auto u : rs) cout << u[0] _ u[1] << nl;

    return 0;
}