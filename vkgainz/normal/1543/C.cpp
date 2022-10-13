#include <bits/stdc++.h>
using namespace std;

map<pair<double, double>, double> dp;
double solve(double c, double m, double v) {
    if(dp.find(make_pair(c, m)) != dp.end()) {
        return dp[make_pair(c, m)];
    }
    if(abs(c) <= 1e-15 && abs(m) <= 1e-15)
        dp[make_pair(c, m)] = 1.0;
    else if(abs(c) <= 1e-15)
        dp[make_pair(c, m)] = m * solve(c, max(m - v, 0.0), v) + 1.0;
    else if(abs(m) <= 1e-15)
        dp[make_pair(c, m)] = c * solve(max(c - v, 0.0), m, v) + 1.0;
    else dp[make_pair(c, m)] = c * solve(max(c - v, 0.0), m + min(c, v) / 2, v)
        + m * solve(c + min(m, v) / 2, max(m - v, 0.0), v)
        + 1.0;
    return dp[make_pair(c, m)];
}

int main() {
    int t; cin >> t;
    cout << setprecision(24);
    while(t--) {
        double c, m, p, v; cin >> c >> m >> p >> v;
        dp.clear();
        solve(c, m, v);
        cout << dp[make_pair(c, m)] << "\n";
    }
}