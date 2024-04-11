#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 5;
bitset<maxn> ans, prv;

namespace segtree {
    vector<int> st[maxn * 4];
    void modify(int l, int r, int ql, int qr, int v, int o = 0) {
        if (l >= qr || ql >= r) return;
        if (l >= ql && r <= qr) return st[o].push_back(v), void();
        modify(l, (l + r) / 2, ql, qr, v, o * 2 + 1);
        modify((l + r) / 2, r, ql, qr, v, o * 2 + 2);
    }
    void solve(int l, int r, int o = 0) {
        bitset<maxn> tmp = prv;
        for (int i = 0; i < st[o].size(); ++i) prv |= prv << st[o][i];
        if (r - l == 1) ans |= prv;
        else solve(l, (l + r) / 2, o * 2 + 1), solve((l + r) / 2, r, o * 2 + 2);
        prv = tmp;
    } 
}
int main() {
    int n, q; scanf("%d %d", &n, &q);
    for (int i = 0; i < q; ++i) {
        int l, r, x; scanf("%d %d %d", &l, &r, &x); --l;
        segtree::modify(0, n, l, r, x);
    }
    prv[0] = true;
    segtree::solve(0, n);
    vector<int> v;
    for (int i = 1; i <= n; ++i) if (ans[i]) v.push_back(i);
    printf("%d\n", (int)v.size());
    for (int i = 0; i < v.size(); ++i) printf("%d ", v[i]); puts("");
    return 0;
}