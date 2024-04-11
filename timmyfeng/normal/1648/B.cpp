#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c; cin >> n >> c;

    vector<bool> present(c + 1);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        present[a] = true;
    }

    vector<int> prefix(c + 1);
    for (int i = 1; i <= c; ++i)
        prefix[i] = prefix[i - 1] + present[i];

    bool integral = true;
    for (int i = 1; i <= c; ++i) {
        if (present[i]) {
            for (int j = i - 1; j <= c; j += i) {
                integral &= present[j / i + 1] || prefix[min(c, j + i)] - prefix[j] == 0;
            }
        }
    }

    cout << (integral ? "Yes" : "No") << "\n";
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}