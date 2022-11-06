#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn], x[maxn], ans[maxn];

struct Query {
    int l, r, id;
    bool operator<(const Query& rhs) const {
        return r < rhs.r;
    }
} qry[maxn];

struct BIT {
    int _bit[maxn];
    void init() {
        memset(_bit, 0, sizeof(_bit));
    }
#define lowbit(x) (x & -x)
    void add(int x, int v) {
        if (x == 0) return;
        for (int i = x; i < maxn; i += lowbit(i)) _bit[i] ^= v;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret ^= _bit[i];
        return ret;
    }
#undef lowbit
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], x[i] = x[i - 1] ^ a[i];
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> qry[i].l >> qry[i].r;
        qry[i].id = i;
    }
    sort(qry, qry + m); bit.init();
    int ind = 0;
    map<int, int> pos;
    for (int i = 1; i <= n; ++i) {
        while (ind < m && qry[ind].r < i) ++ind;
        bit.add(pos[a[i]], a[i]); bit.add(i, a[i]); pos[a[i]] = i;
        while (ind < m && qry[ind].r == i) ans[qry[ind].id] = bit.qry(qry[ind].r) ^ bit.qry(qry[ind].l - 1) ^ x[qry[ind].r] ^ x[qry[ind].l - 1], ++ind;
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << endl;
    return 0;
}