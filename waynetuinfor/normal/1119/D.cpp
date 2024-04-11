#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long inf = 1000000000000000000;
long long s[maxn], d[maxn], l[maxn], r[maxn];
long long lb[maxn], rb[maxn], ans[maxn], sum;
int fa[maxn], cnt;

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    --cnt;
    fa[x] = y;
    sum -= rb[x] - lb[x];
    sum -= rb[y] - lb[y];
    lb[y] = min(lb[y], lb[x]);
    rb[y] = max(rb[y], rb[x]);
    sum += rb[y] - lb[y];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &s[i]);
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        long long nxt = i + 1 < n ? s[i + 1] : inf;
        d[i] = nxt - s[i];
    }
    int q; scanf("%d", &q);
    vector<int> qr;
    for (int i = 0; i < q; ++i) {
        scanf("%lld%lld", &l[i], &r[i]);
        qr.push_back(i);
    }
    sort(qr.begin(), qr.end(), [&](int i, int j) {
        return r[i] - l[i] < r[j] - l[j];
    });

    vector<int> v;
    for (int i = 0; i < n; ++i) v.push_back(i);
    sort(v.begin(), v.end(), [&](int i, int j) {
        return d[i] < d[j];
    });

    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        lb[i] = s[i];
        rb[i] = s[i];
    }
    cnt = n;
    for (int i = 0, j = 0; i < q; ++i) {
        while (j < n && d[v[j]] <= r[qr[i]] - l[qr[i]]) {
            if (v[j] + 1 < n)
                merge(v[j], v[j] + 1);
            ++j;
        }
        ans[qr[i]] = sum + (r[qr[i]] - l[qr[i]] + 1) * cnt;
        // ans[qr[i]] -= max(0ll, s[n - 1] + (r[qr[i]] - l[qr[i]]) - inf);
    }

    for (int i = 0; i < q; ++i) printf("%lld ", ans[i]);
    puts("");
    return 0;
}