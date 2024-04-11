#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxp = 100 + 5;
const long long inf = 1e14;
long long cs[maxn], c[maxn], d[maxn], dp[maxp][maxn];

struct line {
    long long a, b;
    long long operator()(const long long &x) const { return a * x + b; }
    long long inter(const line &rhs) const { return (rhs.b - b) / (a - rhs.a); }
    bool checkfront(const line &rhs, const long long &x) const { return (*this)(x) <= rhs(x); }
    bool checkback(const line &l1, const line &l2) const { return a == l1.a ? b <= l1.b : inter(l2) <= l1.inter(l2); }
    friend ostream& operator<<(ostream &out, const line &l) { out << "a = " << l.a << " b = " << l.b; return out; }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, p; cin >> n >> m >> p;
    for (int i = 2; i <= n; ++i) cin >> d[i], d[i] += d[i - 1];
    for (int i = 1; i <= m; ++i) {
        int h, t; cin >> h >> t;
        c[i] = t - d[h];
    }
    sort(c + 1, c + m + 1);
    for (int i = 1; i <= m; ++i) cs[i] = cs[i - 1] + c[i];
    fill(&dp[0][0], &dp[maxp - 1][maxn - 1] + 1, inf);
    dp[0][0] = 0;
    for (int i = 1; i <= p; ++i) {
        deque<line> dq;
        dq.push_back((line){ 0, dp[i - 1][0] });
        for (int j = 1; j <= m; ++j) {
            while (dq.size() >= 2 && dq[1].checkfront(dq[0], c[j])) dq.pop_front();
            dp[i][j] = j * c[j] - cs[j] + dq.front()(c[j]);
            if (j == m) break;
            long long a = -j, b = dp[i - 1][j] + cs[j];
            while (dq.size() >= 2 && (line){ a, b }.checkback(dq[dq.size() - 1], dq[dq.size() - 2])) dq.pop_back();
            if (dq.back().a == a && dq.back().b <= b) continue;
            dq.push_back((line){ a, b });
        }
    }
    long long ans = inf;
    for (int i = 1; i <= p; ++i) ans = min(ans, dp[i][m]);
    cout << ans << endl;
    return 0;
}