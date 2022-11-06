#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const long double inf = 1e16;
long double st[maxn], s[maxn], tinv[maxn], dp[maxn];
int n, k, from[maxn];

struct line {
    long double a, b;
    int pos;
    long double operator()(const double &x) const { return a * x + b; }
    long double inter(const line &rhs) const { return (rhs.b - b) / (a - rhs.a); }
};

int check(long double cost, long double &ret) {
    dp[0] = 0;
    deque<line> dq; dq.push_back({ 0, 0, 0 });
    for (int i = 1; i <= n; ++i) {
        while (dq.size() >= 2 && dq[1](tinv[i]) <= dq[0](tinv[i])) dq.pop_front();
        dp[i] = dq[0](tinv[i]) + st[i] + cost;
        from[i] = dq[0].pos;
        line ins = { -s[i], tinv[i] * s[i] - st[i] + dp[i], i };
        while (dq.size() >= 2 && ins.inter(dq[dq.size() - 2]) <= dq[dq.size() - 1].inter(dq[dq.size() - 2])) dq.pop_back();
        dq.push_back(ins);
    }
    int seg = 0, now = n;
    while (now) {
        ++seg;
        now = from[now];
    }
    ret = dp[n];
    return seg;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int t; scanf("%d", &t);
        tinv[i] = tinv[i - 1] + 1.0 / t;
        s[i] = s[i - 1] + t;
        st[i] = st[i - 1] + 1.0 * s[i] / t;
    }
    int step = 66;
    long double r = inf, l = 0, ans;
    long double cost = -1;
    while (step--) {
        long double m = (l + r) * 0.5;
        if (check(m, ans) <= k) r = m, cost = m;
        else l = m;
    }
    check(cost, ans);
    printf("%.20Lf\n", ans - k * cost);
    return 0;
}