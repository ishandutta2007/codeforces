#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
long long s[maxn], p[maxn], a[maxn], b[maxn], x[maxn];
long long f[maxn];

struct line {
    long long a, b;
    long long operator()(const long long &x) const { return a * x + b; }
    long double inter(const line &rhs) const { return 1.0 * (rhs.b - b) / (a - rhs.a); }
    bool kill(const line &pivot, const line &rhs) const { return inter(pivot) < rhs.inter(pivot); }
};

void cdq(const vector<int> &slope, const vector<int> &query, int l, int r) {
    if (l == r) return;
    if (slope.size() == 0 || query.size() == 0) return;
    int m = l + r >> 1;
    deque<line> dq;
    for (int i = 0; i < slope.size(); ++i) if (slope[i] <= m) {
        line ins = { a[slope[i]], b[slope[i]] };
        while (dq.size() >= 2 && ins.kill(dq[dq.size() - 2], dq[dq.size() - 1])) dq.pop_back();
        dq.push_back(ins);
    }
    for (int i = 0; i < query.size(); ++i) if (query[i] > m) {
        while (dq.size() >= 2 && dq[0](x[query[i]]) <= dq[1](x[query[i]])) dq.pop_front();
        f[query[i]] = max(f[query[i]], dq[0](x[query[i]]));
    }
    vector<int> lslope, rslope, lquery, rquery;
    for (int i = 0; i < slope.size(); ++i) {
        if (slope[i] <= m) lslope.push_back(slope[i]);
        else rslope.push_back(slope[i]);
    }
    for (int i = 0; i < query.size(); ++i) {
        if (query[i] <= m) lquery.push_back(query[i]);
        else rquery.push_back(query[i]);
    }
    cdq(lslope, lquery, l, m); cdq(rslope, rquery, m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        long long a; cin >> a;
        s[i] = s[i - 1] + a;
        p[i] = p[i - 1] + i * 1ll * a;
    }
    for (int i = 0; i < n; ++i) a[i] = -i;
    for (int i = 0; i < n; ++i) b[i] = i * s[i] - p[i];
    for (int i = 1; i <= n; ++i) x[i] = s[i];
    vector<int> slope, query;
    for (int i = 0; i < n; ++i) slope.push_back(i), query.push_back(i + 1);
    sort(slope.begin(), slope.end(), [&](const int &i, const int &j) { return a[i] < a[j]; });
    sort(query.begin(), query.end(), [&](const int &i, const int &j) { return x[i] < x[j]; });
    cdq(slope, query, 1, n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, f[i] + p[i]);
    cout << ans << endl;
    return 0;
}