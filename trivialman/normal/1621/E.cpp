#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e9;
const int N = 1e5 + 5, MAX = 1e5;
mt19937 rng(time(0));

int T, n, m, k;
int a[N];
vector<int> b[N];
LL sum[N];
char ans[2 * N];
int d[N], tr[(1 << 18) + 5], lz[(1 << 18) + 5];

void build(int i = 1, int l = 1, int r = MAX) {
    if (l == r) {
        tr[i] = d[l];
        return;
    }
    int m = l + r >> 1;
    build(i << 1, l, m);
    build(i << 1 | 1, m + 1, r);
    tr[i] = min(tr[i << 1], tr[i << 1 | 1]);
}

void app(int i, int a, int l, int r) {
    lz[i] = lz[i] + a;
    tr[i] = tr[i] + a;
}

void pushdown(int i, int l, int m, int r) {
    app(i << 1, lz[i], l, m);
    app(i << 1 | 1, lz[i], m + 1, r);
    lz[i] = 0;
}

void update(int l1, int r1, int x, int i = 1, int l2 = 1, int r2 = MAX) {
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
    tr[i] = min(tr[i << 1], tr[i << 1 | 1]);
}

int query(int l1, int r1, int i = 1, int l2 = 1, int r2 = MAX) {
    if (l1 <= l2 && r2 <= r1)
        return tr[i];
    int m2 = l2 + r2 >> 1;
    pushdown(i, l2, m2, r2);
    return min(l1 <= m2 ? query(l1, r1, i << 1, l2, m2) : INF, m2 < r1 ? query(l1, r1, i << 1 | 1, m2 + 1, r2) : INF);
}

inline int updiv(LL x, LL y) { return (x - 1) / y + 1; }

int main() {
    cin >> T;
    while (T--) {
        scanf("%d%d", &n, &m);
        rep(i, 1, n) scanf("%d", a + i);
        memset(tr, 0, sizeof tr);
        memset(lz, 0, sizeof lz);
        sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1);
        rep(i, 1, m) update(1, a[i], 1);

        rep(i, 1, m) {
            scanf("%d", &k), b[i].resize(k);
            sum[i] = 0;
            rep(j, 0, k - 1) scanf("%d", &b[i][j]), sum[i] += b[i][j];
            update(1, updiv(sum[i], k), -1);
        }

        int idx = 0;
        rep(i, 1, m) {
            k = b[i].size();
            update(1, updiv(sum[i], k), 1);
            rep(j, 0, k - 1) {
                int avg = updiv(sum[i] - b[i][j], k - 1);
                //cerr << i << " " << j << " " << avg << endl;
                update(1, avg, -1);
                ans[++idx] = query(1, MAX) >= 0 ? '1' : '0';
                update(1, avg, 1);
            }
            update(1, updiv(sum[i], k), -1);
        }
        ans[++idx] = 0;
        printf("%s\n", ans + 1);
        //cerr << endl;
    }
    return 0;
}