#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> p(n);
    for (auto &i : p) cin >> i, --i;

    vector<bool> is_right(n);
    vector<long long> matches(n);

    long long answer = 0;
    for (int c = n - 1; c >= 0; --c) {
        for (int b = 0; b < n; ++b) {
            matches[b] = (b ? matches[b - 1] : 0) + is_right[b];
        }

        long long total_matches = 0;
        for (int a = c - 1; a >= 0; --a) {
            if (p[a] < p[c]) answer += total_matches;
            total_matches += matches[p[a]];
        }
        is_right[p[c]] = true;
    }

    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}