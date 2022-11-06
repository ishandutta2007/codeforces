#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];
int l[maxn], r[maxn], ans[maxn], st[maxn];
vector<int> qr[maxn];

namespace segtree {
    int st[maxn * 4], tg[maxn * 4];
    void push(int o) {
        if (tg[o] == 0) return;
        st[o * 2 + 1] += tg[o], tg[o * 2 + 1] += tg[o];
        st[o * 2 + 2] += tg[o], tg[o * 2 + 2] += tg[o];
        tg[o] = 0;
    }
    void modify(int l, int r, int ql, int qr, int v, int o = 0) {
        // printf("modify ql = %d qr = %d v = %d\n", ql, qr, v);
        if (r - l > 1) push(o);
        if (l >= qr || ql >= r) return;
        if (l >= ql && r <= qr) return st[o] += v, tg[o] += v, void();
        modify(l, (l + r) / 2, ql, qr, v, o * 2 + 1), modify((l + r) / 2, r, ql, qr, v, o * 2 + 2);
        st[o] = max(st[o * 2 + 1], st[o * 2 + 2]);
    }
    int query(int l, int r, int ql, int qr, int o = 0) {
        if (r - l > 1) push(o);
        if (l >= qr || ql >= r) return 0;
        if (l >= ql && r <= qr) return st[o];
        return max(query(l, (l + r) / 2, ql, qr, o * 2 + 1), query((l + r) / 2, r, ql, qr, o * 2 + 2));
    }
}

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int m; scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &l[i], &r[i]);
        qr[r[i]].push_back(i);
    }
    // printf("n = %d\n", n);
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') st[p++] = i;
        else if (p > 0) segtree::modify(1, n + 1, 1, st[--p] + 1, 2);
        for (int j = 0; j < qr[i].size(); ++j) {
            // printf("i = %d l = %d r = %d\n", qr[i][j], l[qr[i][j]], r[qr[i][j]]);
            ans[qr[i][j]] = segtree::query(1, n + 1, l[qr[i][j]], r[qr[i][j]] + 1);
        }
    }
    for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    return 0;
}