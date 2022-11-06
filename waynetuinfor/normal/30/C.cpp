#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
double dp[maxn];

struct target { double x, y, t, p; } tar[maxn];

double dist(const target &a, const target &b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> tar[i].x >> tar[i].y >> tar[i].t >> tar[i].p;
    sort(tar + 1, tar + 1 + n, [](const target &a, const target &b) { return a.t < b.t; });
    for (int i = 1; i <= n; ++i) {
        dp[i] = tar[i].p;
        for (int j = 1; j < i; ++j) {
            if (tar[i].t - tar[j].t >= dist(tar[i], tar[j])) dp[i] = max(dp[i], dp[j] + tar[i].p);
        }
    }
    double ans = 0.0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}