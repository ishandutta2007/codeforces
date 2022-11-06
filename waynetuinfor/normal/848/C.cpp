#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
struct query { int tp, ps, l, r, t, id; };
int ans[maxn], a[maxn], ti;
vector<query> qry;
set<int> st[maxn];

void insert(int prv, int p) { ++ti, qry.push_back({ 1, prv, p, p - prv, ti, 0 }); }
void erase(int prv, int p) { ++ti, qry.push_back({ 1, prv, p, prv - p, ti, 0 }); }

void ask(int l, int r, int id) {
    ++ti;
    qry.push_back({ 2, r, l, r, ti, id });
    qry.push_back({ 3, l - 1, l, r, ti, id });
}

struct fenwick {
    int data[maxn];
    void init() { memset(data, 0, sizeof(data)); }
    void add(int x, int v) { for (; x < maxn; x += x & -x) data[x] += v; }
    int qry(int x, int ret = 0) { for (; x; x -= x & -x) ret += data[x]; return ret; }
} bit;

void cdq(const vector<query> &qry, int l, int r) {
    if (l == r) return;
    if (qry.size() == 0) return;
    int m = (l + r) >> 1;
    for (auto q : qry) {
        if (q.t <= m && q.tp == 1) bit.add(q.l, q.r);
        else if (q.t > m && q.tp == 2) ans[q.id] += bit.qry(q.r) - bit.qry(q.l - 1);
        else if (q.t > m && q.tp == 3) ans[q.id] -= bit.qry(q.r) - bit.qry(q.l - 1);
    }
    for (auto q : qry) {
        if (q.t <= m && q.tp == 1) bit.add(q.l, -q.r);
    }
    vector<query> ql, qr;
    for (auto q : qry) {
        if (q.t <= m) ql.push_back(q);
        else qr.push_back(q);
    }
    cdq(ql, l, m); cdq(qr, m + 1, r);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        st[a[i]].insert(i); 
    }
    for (int i = 1; i <= n; ++i) if (st[i].size()) {
        for (auto it = st[i].begin(); next(it) != st[i].end(); ++it) insert(*it, *next(it));
    }
    int ptr = 0;
    for (int i = 0; i < m; ++i) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) {
            int o = a[l];
            auto it = st[o].find(l);
            if (it != st[o].begin()) erase(*prev(it), *it); 
            if (next(it) != st[o].end()) erase(*it, *next(it));
            if (it != st[o].begin() && next(it) != st[o].end()) insert(*prev(it), *next(it));
            st[o].erase(l);
            st[r].insert(l); it = st[r].find(l);
            if (it != st[r].begin()) insert(*prev(it), *it);
            if (next(it) != st[r].end()) insert(*it, *next(it));
            if (it != st[r].begin() && next(it) != st[r].end()) erase(*prev(it), *next(it));
            a[l] = r;
            continue;
        }
        ask(l, r, ++ptr);
    }
    sort(qry.begin(), qry.end(), [](const query &i, const query &j) { return i.ps == j.ps ? i.tp < j.tp : i.ps < j.ps; });
    bit.init(); cdq(qry, 1, ti);
    for (int i = 1; i <= ptr; ++i) cout << ans[i] << endl;
    return 0;
}