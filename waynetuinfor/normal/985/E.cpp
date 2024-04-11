#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int a[maxn], b[maxn];
bool ans[maxn];

namespace bit {
    int dat[maxn];
    void init() { 
        for (int i = 0; i < maxn; ++i)
            dat[i] = maxn;
    }
    void add(int p, int v) {
        for (; p < maxn; p += p & -p)
            dat[p] = min(dat[p], v);
    }
    int qry(int p) {
        int v = maxn;
        for (; p; p -= p & -p)
            v = min(v, dat[p]);
        return v;
    }
}

int main() {
    int n, k, d; scanf("%d %d %d", &n, &k, &d);
    vector<int> ds;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), ds.push_back(a[i]);
    sort(a + 1, a + n + 1, greater<int>()); sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 1; i <= n; ++i) b[i] = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin() + 1;
    bit::init();
    bit::add(b[1], 0);
    for (int i = 1; i <= n; ++i) {
        int r = upper_bound(ds.begin(), ds.end(), a[i] + d) - ds.begin();
        int t = bit::qry(r);
        if (i - t >= k) {
            ans[i] = true;
            if (i + 1 <= n) bit::add(b[i + 1], i);
        }
    }
    ans[n] ? puts("YES") : puts("NO");
    return 0;
}