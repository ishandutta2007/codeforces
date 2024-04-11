#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> xs(n);
    for (auto& x : xs) cin >> x;

    bool sorted = true;
    for (int i = 0; i + 1 < n; ++i) {
        if (xs[i] > xs[i + 1]) sorted = false;
    }

    if (sorted) {
        cout << "0\n";
    } else if (xs.front() == 1 || xs.back() == n) {
        cout << "1\n";
    } else if (xs.back() != 1 || xs.front() != n) {
        cout << "2\n";
    } else {
        cout << "3\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}