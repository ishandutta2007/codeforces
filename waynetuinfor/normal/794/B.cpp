#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double n, h; cin >> n >> h;
    double a = h / 2.0 / n;
    double r = n; vector<double> ans;
    for (int i = 0; i < n - 1; ++i) {
        // double sq = sqrt(r);
        ans.push_back(h * sqrt(r - 1) / sqrt(r));
        // cout << fixed << setprecision(10) << h * (sqrt(r - 1) / sqrt(r)) << ;
        h *= (sqrt(r - 1) / sqrt(r));
        --r;
    }
    reverse(ans.begin(), ans.end());
    for (double d : ans) cout << fixed << setprecision(10) << d << ' ';
    return 0;
}