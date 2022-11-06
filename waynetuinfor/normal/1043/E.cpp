#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int x[maxn], y[maxn];
long long ans[maxn];
pair<long long, int> bitx[maxn], bity[maxn];

void add(int p, int v, pair<long long, int> *bit) {
    for (; p < maxn; p += p & -p) {
        bit[p].first += v;
        bit[p].second += 1;
    }
}

pair<long long, int> query(int p, pair<long long, int> *bit) {
    pair<long long, int> res = make_pair(0, 0);
    for (; p; p -= p & -p) {
        res.first += bit[p].first;
        res.second += bit[p].second;
    }
    return res;
}

pair<long long, int> operator-(const pair<long long, int> &a, const pair<long long, int> &b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        ans[u] -= min(x[u] + y[v], x[v] + y[u]);
        ans[v] -= min(x[u] + y[v], x[v] + y[u]);
    }
    vector<int> ds;
    for (int i = 0; i < n; ++i) ds.push_back(x[i] - y[i]);
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) {
        int p = lower_bound(ds.begin(), ds.end(), x[i] - y[i]) - ds.begin() + 1;
        add(p, x[i], bitx);
        add(p, y[i], bity);
    }
    for (int i = 0; i < n; ++i) {
        int p = lower_bound(ds.begin(), ds.end(), x[i] - y[i]) - ds.begin() + 1;
        pair<long long, int> py = query(maxn - 1, bity) - query(p, bity);
        ans[i] += x[i] * 1ll * py.second + py.first;
        pair<long long, int> px = query(p, bitx);
        ans[i] += y[i] * 1ll * px.second + px.first;
        ans[i] -= x[i] + y[i];
    }
    for (int i = 0; i < n; ++i) printf("%lld ", ans[i]);
    puts("");
    return 0;
}