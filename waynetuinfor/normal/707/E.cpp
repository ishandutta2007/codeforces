#include <bits/stdc++.h>
#define x1 aaa
#define y1 bbb
#define x2 ccc
#define y2 ddd
using namespace std;

const int maxn = 2000 + 10;

struct fenwick {
    long long data[maxn][maxn];
    void init() { memset(data, 0, sizeof(data)); }
    void add(int x, int y, int v) {
        for (int i = x; i < maxn; i += i & -i) {
            for (int j = y; j < maxn; j += j & -j) data[i][j] += v;
        }
    }
    long long qry(int x, int y, long long v = 0) {
        for (int i = x; i; i -= i & -i) {
            for (int j = y; j; j -= j & -j) v += data[i][j];
        }
        return v;
    }
} bit;

bool v[maxn];
vector<int> g[maxn];
vector<int> query[maxn];
int x[maxn * maxn], y[maxn * maxn], w[maxn * maxn], x1[maxn], x2[maxn], y1[maxn], y2[maxn];
long long ans[maxn];

void solve(int now) {
    for (int i : g[now]) bit.add(x[i], y[i], w[i]);
    for (int q : query[now]) {
        ans[q] += bit.qry(x2[q], y2[q]) + bit.qry(x1[q] - 1, y1[q] - 1) - bit.qry(x2[q], y1[q] - 1) - bit.qry(x1[q] - 1, y2[q]);
    }
    for (int i : g[now]) bit.add(x[i], y[i], -w[i]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1, p = 0; i <= k; ++i) {
        int c; cin >> c;
        while (c--) {
            ++p; cin >> x[p] >> y[p] >> w[p];
            g[i].push_back(p);
        }
    }
    fill(v, v + maxn, true);
    int q; cin >> q;
    int qid = 0;
    while (q--) {
        string c; cin >> c;
        if (c[0] == 'S') {
            int i; cin >> i;
            v[i] = !v[i];
        } else {
            ++qid;
            cin >> x1[qid] >> y1[qid] >> x2[qid] >> y2[qid];
            for (int i = 1; i <= k; ++i) {
                if (!v[i]) continue;
                query[i].push_back(qid);
            }
        }
    }
    for (int i = 1; i <= k; ++i) solve(i);
    for (int i = 1; i <= qid; ++i) cout << ans[i] << endl;
    return 0;
}