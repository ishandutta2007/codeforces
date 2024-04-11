#include <bits/stdc++.h>
using namespace std;

pair<bool, vector<pair<int, int>>> solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    vector<pair<int, int>> moves;
    auto op = [&](int i, int j) {
        reverse(a.begin() + i, a.begin() + j + 1);
        moves.push_back({i, j});
    };

    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (i == 0) return {false, {}};

            bool reversed_edge = false;
            for (int l = i; l < n && !reversed_edge; ++l) {
                bool contains_pair = false;
                for (int r = l + 1; r < n && !reversed_edge; ++r) {
                    contains_pair |= (a[r] == b[i] && a[r - 1] == b[i - 1]);
                    if (contains_pair && a[l] == a[r]) {
                        reversed_edge = true;
                        op(l, r);
                    }
                }
            }

            int j = i;
            while (j < n && !(a[j] == b[i - 1] && a[j - 1] == b[i])) ++j;

            if (j == n) return {false, {}};

            op(i - 1, j);
        }
    }

    return {true, moves};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        auto [doable, moves] = solve();
        if (doable) {
            cout << "YES\n";
            cout << moves.size() << "\n";
            for (auto &[l, r] : moves) cout << l + 1 << " " << r + 1 << "\n";
        } else {
            cout << "NO\n";
        }
    }
}