#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+ 5;
int l[maxn], r[maxn];

namespace fenwick {
    pair<int, int> dat[maxn];
    void init() { fill(dat, dat + maxn, make_pair(maxn, -1)); }
    void add(int p, pair<int, int> v) { for (; p < maxn; p += p & -p) dat[p] = min(dat[p], v); }
    pair<int, int> qry(int p, pair<int, int> v = make_pair(maxn, -1)) { for (; p; p -= p & -p) v = min(v, dat[p]); return v; }
}

int main() {
    int n; scanf("%d", &n);
    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l[i], &r[i]);
        ds.push_back(l[i]), ds.push_back(r[i]);
    }
    sort(ds.begin(), ds.end()), ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) {
        l[i] = lower_bound(ds.begin(), ds.end(), l[i]) - ds.begin() + 1;
        r[i] = lower_bound(ds.begin(), ds.end(), r[i]) - ds.begin() + 1;
    }
    fenwick::init();
    vector<int> o(n); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return l[i] == l[j] ? r[i] < r[j] : l[i] > l[j]; });
    for (int i = 0; i < n; ++i) {
        int x = o[i];
        int p, v; tie(p, v) = fenwick::qry(r[x]);
        if (v != -1 && p <= r[x]) {
            printf("%d %d\n", v + 1, x + 1);
            return 0;
        }
        fenwick::add(r[x], make_pair(r[x], x));
    }
    puts("-1 -1");
    return 0;
}