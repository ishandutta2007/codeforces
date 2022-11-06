#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int ans[maxn];

struct data { int b, i, r, id; };

struct fenwick {
    int a[maxn];
    void init() { memset(a, 0, sizeof(a)); }
    void add(int x, int v) { for (; x < maxn; x += x & -x) a[x] += v; }
    int qry(int x, int ret = 0) { for (; x; x -= x & -x) ret += a[x]; return ret; }
} bit;

void cdq(const vector<data> &d, int l, int r) {
    if (d.size() == 0) return;
    if (l == r) return;
    int m = (l + r) >> 1;
    for (auto &dt : d) {
        if (dt.i > m) bit.add(dt.r, 1);
        else ans[dt.id] += bit.qry(maxn - 1) - bit.qry(dt.r);
    } 
    for (auto &dt : d) {
        if (dt.i > m) bit.add(dt.r, -1);
    }
    vector<data> dl, dr;
    for (auto &dt : d) {
        if (dt.i > m) dr.push_back(dt);
        else dl.push_back(dt);
    }
    cdq(dl, l, m); cdq(dr, m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> dsr, dsi;
    vector<data> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i].b, d[i].id = i;
    for (int i = 0; i < n; ++i) cin >> d[i].i, dsi.push_back(d[i].i);
    for (int i = 0; i < n; ++i) cin >> d[i].r, dsr.push_back(d[i].r);
    sort(dsr.begin(), dsr.end()); dsr.resize(unique(dsr.begin(), dsr.end()) - dsr.begin());
    sort(dsi.begin(), dsi.end()); dsi.resize(unique(dsi.begin(), dsi.end()) - dsi.begin());
    for (int i = 0; i < n; ++i) {
        d[i].r = lower_bound(dsr.begin(), dsr.end(), d[i].r) - dsr.begin() + 1;
        d[i].i = lower_bound(dsi.begin(), dsi.end(), d[i].i) - dsi.begin() + 1;
    }
    sort(d.begin(), d.end(), [](const data &d1, const data &d2) { return d1.b == d2.b ? d1.i < d2.i : d1.b > d2.b; });
    bit.init();
    cdq(d, 1, n);
    int c = 0;
    for (int i = 0; i < n; ++i) if (ans[i] > 0) ++c;
    cout << c << endl;
    return 0;
}