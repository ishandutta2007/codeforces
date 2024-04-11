#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];

namespace segtree {
    struct data {
        int pfx, pfn, sum;
        data(int x = 0): pfx(x), pfn(x), sum(x) {}
        data(int x, int y, int z): pfx(x), pfn(y), sum(z) {}
        data operator+(const data &d) const {
            return data(max(pfx, sum + d.pfx),
                        min(pfn, sum + d.pfn), sum + d.sum);
        }
    } st[maxn * 4];
    void build(int l, int r, int o = 0) {
        if (r - l == 1) {
            if (s[l] == '(') st[o] = data(1);
            else st[o] = data(-1);
            return;
        }
        build(l, (l + r) >> 1, o * 2 + 1);
        build((l + r) >> 1, r, o * 2 + 2);
        st[o] = st[o * 2 + 1] + st[o * 2 + 2];
    }
    data query(int l, int r, int ql, int qr, int o = 0) {
        if (l >= qr || ql >= r) return data(0);
        if (l >= ql && r <= qr) return st[o];
        return query(l, (l + r) >> 1, ql, qr, o * 2 + 1) +
               query((l + r) >> 1, r, ql, qr, o * 2 + 2);
    }
}

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    segtree::build(0, n);
    int c = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (c < 0) break;
        if (s[i] == '(') c--;
        else c++;
        segtree::data res = segtree::query(0, n, i + 1, n);
        if (res.pfn + c >= 0 && res.pfx + c >= 0 && res.sum + c == 0) ++ans;
        if (s[i] == '(') c += 2;
        else c -= 2;
    }
    printf("%d\n", ans);
    return 0;
}