#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, inf = 1e9;
const double eps = 1e-9;
int n, l;

struct data {
    double f, p, rt;
    data(int r, int _p, double _rt): f(sqrt(abs(r - l))), p(_p), rt(_rt) {}
    data(double _f, double _p, double _rt): f(_f), p(_p), rt(_rt) {}
    data() {}
    double operator()() const { return f - rt * p; }
    data operator+(const data& d) const { return data(f + d.f, p + d.p, rt); }
    bool operator<(const data& d) const { return (*this)() < d(); }
    bool operator>(const data& d) const { return (*this)() > d(); }
};

data dp[maxn];
int t[maxn], x[maxn], b[maxn];

bool check(double rt) {
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; ++i) {
        dp[i] = data(x[i], b[i], rt);
        for (int j = 1; j < i; ++j) {
            if (dp[i] > dp[j] + data(x[i] - x[j], b[i], rt)) {
                dp[i] = dp[j] + data(x[i] - x[j], b[i], rt);
                t[i] = j;
            }
        }
    }
    return dp[n]() <= 0.0;
}

double bs(double l, double r) {
    if (r - l < eps) return l;
    double m = (l + r) / 2.0;
    if (check(m)) return bs(l, m);
    return bs(m, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> b[i];
    double ansr = bs(0, inf);
    check(ansr);
    int now = n;
    stack<int> ans;
    while (now) {
        ans.push(now);
        now = t[now];
    }
    while (ans.size()) cout << ans.top() << ' ', ans.pop();
    cout << endl;
    return 0;
}