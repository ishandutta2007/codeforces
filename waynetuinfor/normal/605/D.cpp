#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 5;
int a[maxn], b[maxn], c[maxn], d[maxn];
int dp[maxn], fr[maxn];

namespace fenwick {
    vector<pair<int, int>> dat[maxn];
    void init() { for (int i = 0; i < maxn; ++i) dat[i].clear(); }
    void add(int p, int a, int i) { for (; p < maxn; p += p & -p) dat[p].emplace_back(a, i); }
    void qry(int p, int a, int f, queue<int> &q) {
        for (; p; p -= p & -p) {
            while (dat[p].size() && dat[p].back().first <= a) {
                if (dp[dat[p].back().second] == -1) 
                    dp[dat[p].back().second] = dp[f] + 1, fr[dat[p].back().second] = f, q.push(dat[p].back().second);
                dat[p].pop_back();
            }
        }
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        ds.push_back(a[i]), ds.push_back(b[i]);
        ds.push_back(c[i]), ds.push_back(d[i]);
    }
    sort(ds.begin(), ds.end()), ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin() + 1;
        b[i] = lower_bound(ds.begin(), ds.end(), b[i]) - ds.begin() + 1;
        c[i] = lower_bound(ds.begin(), ds.end(), c[i]) - ds.begin() + 1;
        d[i] = lower_bound(ds.begin(), ds.end(), d[i]) - ds.begin() + 1;
    }
    queue<int> q;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        if (ds[a[i] - 1] == 0 && ds[b[i] - 1] == 0) q.push(i), dp[i] = 0;
    }
    vector<int> o;
    for (int i = 0; i < n; ++i) if (dp[i] == -1) o.push_back(i);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return b[i] > b[j]; });
    fenwick::init();
    for (int i = 0; i < o.size(); ++i) fenwick::add(a[o[i]], b[o[i]], o[i]);
    memset(fr, -1, sizeof(fr));
    while (q.size()) {
        int x = q.front(); q.pop();
        fenwick::qry(c[x], d[x], x, q); 
    }
    if (dp[n - 1] == -1) return 0 * puts("-1");
    int now = n - 1;
    vector<int> s;
    while (~now) {
        s.push_back(now);
        now = fr[now];
    }
    printf("%d\n", s.size());
    for (int i = s.size() - 1; i >= 0; --i) printf("%d ", s[i] + 1); puts("");
    return 0;
}