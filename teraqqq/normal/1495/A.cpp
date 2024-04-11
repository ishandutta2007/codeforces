#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> x, y;
    for (int i = 0; i < 2*n; ++i) {
        ll px, py; cin >> px >> py;
        if (!py) x.push_back(px * px);
        if (!px) y.push_back(py * py);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += sqrt(x[i] + y[i]);
    }
    cout << setprecision(9) << fixed << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}