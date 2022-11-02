#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<int> xs(m);
    for (auto& x : xs) cin >> x;
    sort(xs.begin(), xs.end());

    if (a > b) {
        a = n + 1 - a;
        b = n + 1 - b;
    }
    // a < b

    m = min(m, b - a - 1);
    int tlim = b - 1;

    int ok = 0, ng = m + 1;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;

        bool judge = true;
        for (int t = 1; t <= mid; ++t) {
            if (t + xs[mid - t] > tlim) judge = false;
        }

        if (judge) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}