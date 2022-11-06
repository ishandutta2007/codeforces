#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 4e5 + 10, lg = 20;
int p[lg][maxn], to[maxn], dep[maxn], tdep[maxn], tp[lg][maxn];
long long w[maxn], maxv[lg][maxn], tsum[lg][maxn];

void add(int now, int r, int wi) {
    // cout << "add now = " << now << " r = " << r << " w = " << wi << endl;
    w[now] = wi;
    p[0][now] = r; dep[now] = dep[r] + 1; maxv[0][now] = w[r];
    for (int i = 1; ; ++i) {
        if ((1 << i) > dep[now]) break;
        p[i][now] = p[i - 1][p[i - 1][now]];
        maxv[i][now] = max(maxv[i - 1][now], maxv[i - 1][p[i - 1][now]]);
    }
    int tmp = now;
    for (int i = lg - 1; i >= 0; --i) {
        if ((1 << i) > dep[tmp]) continue;
        if (maxv[i][tmp] < w[now]) tmp = p[i][tmp];
    }
    tmp = p[0][tmp];
    tp[0][now] = tmp;
    if (tmp == now || tmp == 0) {
        tdep[now] = 0;
        return;
    }
    tdep[now] = tdep[tmp] + 1;
    tsum[0][now] = w[tmp];
    for (int i = 1; ; ++i) {
        if ((1 << i) > tdep[now]) break;
        tp[i][now] = tp[i - 1][tp[i - 1][now]];
        tsum[i][now] = tsum[i - 1][now] + tsum[i - 1][tp[i - 1][now]];
    }
    // cout << "tmp = " << tmp << endl;
}

long long query(int r, long long x) {
    if (w[r] > x) return 0;
    int tmp = r;
    x -= w[r];
    // cout << "x = " << x << endl;
    for (int i = lg - 1; i >= 0; --i) {
        if ((1 << i) > tdep[tmp]) continue;
        if (tsum[i][tmp] <= x) x -= tsum[i][tmp], tmp = tp[i][tmp];
    }
    // cout << "tmp = " << tmp << endl;
    return tdep[r] - tdep[tmp] + 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int cnt = 1;
    long long last = 0;
    int qs; cin >> qs; while (qs--) {
        int t;
        long long p, q; cin >> t >> p >> q;
        p ^= last; q ^= last;
        if (t == 1) add(++cnt, p, q);
        else cout << (last = query(p, q)) << endl;
    }
    return 0;
}