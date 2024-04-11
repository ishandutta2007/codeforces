#include <iostream>
#include <vector>

using namespace std;
using lint = long long;

constexpr lint INF = 1LL << 60;

void solve() {
    int n;
    cin >> n;

    vector<lint> mins(2, INF), sum(2, 0), cnt(2, 0);
    lint ans = INF;

    for (int i = 0; i < n; ++i) {
        lint x;
        cin >> x;

        mins[i % 2] = min(mins[i % 2], x);
        sum[i % 2] += x;
        ++cnt[i % 2];

        if (i == 0) continue;

        lint cost = 0;
        for (int j = 0; j < 2; ++j) {
            cost += sum[j] + (n - cnt[j]) * mins[j];
        }
        ans = min(ans, cost);
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}