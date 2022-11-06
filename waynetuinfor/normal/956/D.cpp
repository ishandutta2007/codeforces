#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const double eps = 1e-9;
int x[maxn], v[maxn], p[maxn];

struct fenwick {
    int dat[maxn];
    void add(int p, int v) { for (; p < maxn; p += p & -p) dat[p] += v; }
    int qry(int p, int v = 0) { for (; p; p -= p & -p) v += dat[p]; return v; }
    void init() { memset(dat, 0, sizeof(dat)); }
} bit;

struct fraction {
    long long p, q;
    fraction(): p(0), q(1) {}
    fraction(long long a): p(a), q(1) {}
    fraction(long long a, long long b): p(a), q(b) { fit(); }
    void fit() { 
        long long g = __gcd(p, q); p /= g; q /= g; 
        if (p < 0 && q < 0) p = -p, q = -q;
        else if (q < 0) p = -p, q = -q; 
    }
    bool operator<(const fraction &rhs) const { return p * rhs.q < q * rhs.p; }
    bool operator>(const fraction &rhs) const { return p * rhs.q > q * rhs.p; }
    bool operator==(const fraction &rhs) const { return p * rhs.q == q * rhs.p; }
    const fraction operator-() const { return fraction(-p, q); }
} s[maxn], e[maxn];

int main() {
    int n, w; scanf("%d %d", &n, &w);
    for (int i = 0; i < n; ++i) scanf("%d %d", x + i, v + i);
    for (int i = 0; i < n; ++i) s[i] = fraction(v[i] - w, x[i]), e[i] = fraction(v[i] + w, x[i]);
    // for (int i = 0; i < n; ++i) printf("s[%d] = %lf e[%d] = %lf\n", i, s[i], i, e[i]);
    vector<int> o(n); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return tie(s[i], -e[i]) < tie(s[j], -e[j]); });
    vector<fraction> ds;
    for (int i = 0; i < n; ++i) ds.push_back(e[i]);
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) p[i] = lower_bound(ds.begin(), ds.end(), e[i]) - ds.begin() + 1;
    // for (int i = 0; i < n; ++i) printf("s[%d] = %lld/%lld, e[%d] = %lld/%lld\n", i, s[i].p, s[i].q, i, e[i].p, e[i].q);
    // for (int i = 0; i < n; ++i) printf("p[%d] = %d\n", i, p[o[i]]);
    bit.init();
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += bit.qry(maxn - 1) - bit.qry(p[o[i]] - 1);
        bit.add(p[o[i]], 1);
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}