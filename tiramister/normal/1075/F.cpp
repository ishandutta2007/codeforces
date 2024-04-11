#include <iostream>
#include <map>
#include <set>

using namespace std;

class UnionFind {
public:
    set<int> node;
    map<int, int> par, diff, num;

    int find(int x) {
        if (!node.count(x)) return -1;
        if (par[x] == x) {
            return x;
        } else {
            int p = find(par[x]);
            diff[x] ^= diff[par[x]];
            return par[x] = p;
        }
    }

    void create(int v) {
        node.insert(v);
        par[v] = v;
        diff[v] = 0;
        num[v] = 1;
    }

    void unite(int x, int y, int w) {
        if (!node.count(x)) create(x);
        if (!node.count(y)) create(y);

        find(x), find(y);
        w ^= diff[x] ^ diff[y];
        x = par[x], y = par[y];
        if (x == y) return;

        if (num[x] < num[y]) swap(x, y);
        num[x] += num[y];
        diff[y] = w;
        par[y] = x;
    }

    bool same(int x, int y) { return find(x) == find(y); }
    bool ispar(int x) { return x == find(x); }
    int size(int x) { return num[find(x)]; }

    int weight(int x, int y) {
        if (!node.count(x) || !node.count(y) || !same(x, y)) return -1;
        return diff[x] ^ diff[y];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int last = 0;
    UnionFind uf;

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y, w;
            cin >> x >> y >> w;
            x ^= last, y ^= last, w ^= last;
            if (x > y) swap(x, y);
            uf.unite(x, ++y, w);
        } else {
            int x, y;
            cin >> x >> y;
            x ^= last, y ^= last;
            if (x > y) swap(x, y);
            last = uf.weight(x, ++y);
            cout << last << '\n';
            if (last < 0) last = 1;
        }
    }
    return 0;
}