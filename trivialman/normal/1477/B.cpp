#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, q;
int a[N], l[N], r[N], tr[(1 << 20) + 5], lz[(1 << 20) + 5];
char s[N], f[N];

void build(int i = 1, int l = 1, int r = n) {
    lz[i] = -1;
    if (l == r) {
        tr[i] = a[l];
        return;
    }
    int m = l + r >> 1;
    build(i << 1, l, m);
    build(i << 1 | 1, m + 1, r);
    tr[i] = tr[i << 1] + tr[i << 1 | 1];
}

void app(int i, int a, int l, int r) {
    if (a != -1) {
        lz[i] = a;
        tr[i] = a * (r - l + 1);
    }
}

void pushdown(int i, int l, int m, int r) {
    app(i << 1, lz[i], l, m);
    app(i << 1 | 1, lz[i], m + 1, r);
    lz[i] = -1;
}

void update(int l1, int r1, LL x, int i = 1, int l2 = 1, int r2 = n) {
    if (l1 <= l2 && r2 <= r1) {
        app(i, x, l2, r2);
        return;
    }
    int m2 = l2 + r2 >> 1;
    pushdown(i, l2, m2, r2);
    if (l1 <= m2)
        update(l1, r1, x, i << 1, l2, m2);
    if (m2 < r1)
        update(l1, r1, x, i << 1 | 1, m2 + 1, r2);
    tr[i] = tr[i << 1] + tr[i << 1 | 1];
}

LL query(int l1, int r1, int i = 1, int l2 = 1, int r2 = n) {
    if (l1 <= l2 && r2 <= r1)
        return tr[i];
    int m2 = l2 + r2 >> 1;
    pushdown(i, l2, m2, r2);
    return (l1 <= m2 ? query(l1, r1, i << 1, l2, m2) : 0) + (m2 < r1 ? query(l1, r1, i << 1 | 1, m2 + 1, r2) : 0);
}

int main() {
    cin >> T;

    rep(cas, 1, T) {
        //cerr << "case " << cas << ":\n";
        scanf("%d%d\n", &n, &q);
        scanf("%s\n%s\n", s + 1, f + 1);
        rep(i, 1, q) scanf("%d%d", l + i, r + i);

        bool flag = true;
        rep(i, 1, n) a[i] = f[i] - '0';
        build();
        //rep(j, 1, n) cerr << query(j, j);
        //cerr << endl;
        rrep(i, q, 1) {
            int sum = query(l[i], r[i]);
            if (sum * 2 == r[i] - l[i] + 1) {
                flag = false;
                break;
            } else if (sum * 2 < r[i] - l[i] + 1) {
                //0 dominate
                update(l[i], r[i], 0);
            } else {
                //1 dominate
                update(l[i], r[i], 1);
            }
            //rep(j, 1, n) cerr << query(j, j);
            //cerr << endl;
        }
        rep(i, 1, n) {
            a[i] = query(i, i);
            if (a[i] + '0' != s[i]) {
                flag = false;
                break;
            }
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}