#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <array>
#include <cassert>

using namespace std;
using ll = long long;

const int MOD = 998244353;

template<int N>
struct Dsu {
    array<int, N> p, r, d;
    array<array<int, N>, 2> h;
    ll hash;

    Dsu() : hash(0) {
        iota(p.begin(), p.end(), 0);
        fill(r.begin(), r.end(), 0);
        fill(d.begin(), d.end(), 0);
        for (int i = 0, z = 2; i < N; ++i) {
            h[0][i] = z;
            h[1][i] = 0;
            z += z;
            if (z >= MOD) z -= MOD;
        }
    }

    pair<int, int> getRoot(int v) {
        if (v == p[v]) return { v, 0 };
        auto [u, x] = getRoot(p[v]);
        return { p[v] = u, d[v] ^= x };
    }

    bool unite(int a, int b) {
        auto [v, x] = getRoot(a);
        auto [u, y] = getRoot(b);
        if (u != v) {
            hash += 2 * MOD - h[0][v] - h[0][u];
            if (r[v] < r[u]) swap(v, u);
            p[u] = v;
            d[u] = x ^ y ^ 1;
            if (d[u]) swap(h[0][u], h[1][u]);
            h[0][v] += h[0][u]; if (h[0][v] >= MOD) h[0][v] -= MOD;
            h[1][v] += h[1][u]; if (h[1][v] >= MOD) h[1][v] -= MOD;
            hash = (hash + h[0][v]) % MOD;
            if (r[v] == r[u]) ++r[v];
            return true;
        } else {
            return false;
        }
    }
};

const int N = 5e5+7;

int n1, n2, m, a[N], b[N], link[N], p2[N];
Dsu<N> dsu;

void processLink(int v, int i) {
    if (link[v] != -1) {
        dsu.unite(link[v], i);
        link[v] = -1;
    } else {
        link[v] = i;
    }
}

void addEdge(int i) {
    int u = a[i], v = b[i];
    dsu.hash += dsu.h[0][i];
    if (dsu.hash >= MOD) dsu.hash -= MOD;
    processLink(u, i);
    processLink(v, i);
}

void printAnswer(int sz) {
    vector<int> res;
    for (int i = 0; i < sz; ++i) {
        if (dsu.getRoot(i).second == 0) {
            res.push_back(i+1);
        }
    }

    cout << res.size();
    for (int x : res) cout << ' ' << x;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n1 >> n2 >> m;
    fill(link, link+N, -1);

    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        b[i] += n1;
        addEdge(i);
    }

    int q; cin >> q;
    int sz = m;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            cin >> a[sz] >> b[sz];
            b[sz] += n1;
            addEdge(sz++);
            cout << dsu.hash << endl;
        } else {
            printAnswer(sz);
        } 
    }
}