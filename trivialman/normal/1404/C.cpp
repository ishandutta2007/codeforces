#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int n, q, x, y;
int a[N], start[N], ans[N];
vector<ar2> b[N];

struct segment_tree {
    int a[(1 << 20) + 5];
    void upd(int i, int x, int l = 1, int r = n, int id = 1) {
        if (l == r) {
            a[id] += x;
            return;
        }
        int m = l + r >> 1;
        if (i <= m)
            upd(i, x, l, m, id << 1);
        else
            upd(i, x, m + 1, r, id << 1 | 1);
        a[id] = a[id << 1] + a[id << 1 | 1];
    }
    int query(int l, int r, int l1 = 1, int r1 = n, int id = 1) {
        if (l <= l1 && r >= r1)
            return a[id];
        int m1 = l1 + r1 >> 1;
        if (r <= m1)
            return query(l, r, l1, m1, id << 1);
        if (l >= m1 + 1)
            return query(l, r, m1 + 1, r1, id << 1 | 1);
        return query(l, r, l1, m1, id << 1) + query(l, r, m1 + 1, r1, id << 1 | 1);
    }
    int find(int x, int l = 1, int r = n, int id = 1) {
        if (x > a[id])
            return -1;
        if (l == r)
            return l;
        int m1 = l + r >> 1;
        if (x <= a[id << 1 | 1])
            return find(x, m1 + 1, r, id << 1 | 1);
        else
            return find(x - a[id << 1 | 1], l, m1, id << 1);
    }
} tr;

int main() {
    cin >> n >> q;
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, q) scanf("%d%d", &x, &y), b[n - y].PB({i, x});
    memset(start, -1, sizeof start);
    rep(i, 1, n) {
        if (a[i] == i)
            start[i] = i;
        else if (a[i] < i)
            start[i] = tr.find(i - a[i]);
        if (start[i] > 0)
            tr.upd(start[i], 1);
        for (ar2 qry : b[i]) {
            int id = qry[0], x = qry[1];
            ans[id] = tr.query(x + 1, n);
        }
        //cerr << i << " " << a[i] << " " << start[i] << " " << tr.query(1, n) << endl;
    }
    rep(i, 1, q) printf("%d\n", ans[i]);
    return 0;
}