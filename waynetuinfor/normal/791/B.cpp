#include <bits/stdc++.h>
using namespace std;

const int maxn = 150000 + 5;
typedef long long LL;

struct DisjointSet {
    struct Osas {
        int id, sz, edge;
    } djs[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) djs[i].id = i, djs[i].sz = 1, djs[i].edge = 0;
    }
    int find(int x) { return djs[x].id == x ? x : djs[x].id = find(djs[x].id); }
    void Union(int x, int y) {
        x = find(x), y = find(y);
        ++djs[x].edge;
        if (x == y) return;
        djs[x].sz += djs[y].sz;
        djs[y].id = x;
        djs[x].edge += djs[y].edge;
    }
    bool valid() {
        for (int i = 0; i < maxn; ++i) if (djs[find(i)].edge != (LL)djs[find(i)].sz * (LL)(djs[find(i)].sz - 1) / 2) return false;
        return true;
    }
} djs;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    djs.init();
    while (m--) {
        int a, b; cin >> a >> b;
        djs.Union(a, b);
    }
    cout << (djs.valid() ? "YES\n" : "NO\n");
    return 0;
}