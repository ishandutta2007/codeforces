#include <iostream>
#include <vector>

using namespace std;
using lint = long long;

void solve() {
    int n;
    cin >> n;

    vector<lint> xs(n), ys(n);
    for (auto& x : xs) cin >> x;
    for (auto& y : ys) cin >> y;

    lint dmax = 0;
    auto diff = vector(n + 1, vector(n + 1, 0LL));
    for (int d = 2; d <= n; ++d) {
        for (int l = 0; l + d <= n; ++l) {
            int r = l + d;
            diff[l][r] = diff[l + 1][r - 1] +
                         (xs[l] * ys[r - 1] + xs[r - 1] * ys[l]) -
                         (xs[l] * ys[l] + xs[r - 1] * ys[r - 1]);
            dmax = max(dmax, diff[l][r]);
        }
    }

    lint sum = 0;
    for (int i = 0; i < n; ++i) sum += xs[i] * ys[i];

    cout << sum + dmax << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}