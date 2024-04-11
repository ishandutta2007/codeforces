#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, y;
    cin >> n >> y;

    vector<int> xs(n);
    for (auto& x : xs) cin >> x;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += xs[i];
        if (sum != y) continue;

        if (i + 1 < n) {
            swap(xs[i], xs[i + 1]);
            break;
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (auto x : xs) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}