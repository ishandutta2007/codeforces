#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int maxn = 1e6 + 5;
vector<int> g[maxn];
int ans[maxn];

struct data {
    int offset, ansc, ansx;
    cc_hash_table<int, int> tab;
    data(): offset(0), ansc(-1), ansx(-1) { tab.clear(); }
    int size() const { return tab.size(); }
};

void merge(data *a, data *b) {
    int diff = b->offset - a->offset;
    for (auto i : b->tab) {
        a->tab[i.first + diff] += i.second;
        if (a->tab[i.first + diff] > a->ansc || a->tab[i.first + diff] == a->ansc && i.first + diff < a->ansx) {
            a->ansc = a->tab[i.first + diff];
            a->ansx = i.first + diff;
        }
    }
}

data *dfs(int x, int p) {
    data *r = new data();
    r->ansc = 1, r->ansx = 0;
    r->tab[0]++;
    for (int u : g[x]) if (u != p) {
        data *d = dfs(u, x);
        if (r->size() < d->size()) swap(r, d);
        merge(r, d);
    }
    ans[x] = r->ansx + r->offset;
    r->offset++;
    return r;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    return 0;
}