#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> p[i][j];
        }
    }
    auto solve = [&](auto &self, vector<int> a, int d) {
        if (d == 2) {
            sort(a.begin(), a.end(), [&](int i, int j) {
                return p[i][d] < p[j][d];
            });
            for (int i = 0; i + 1 < (int)a.size(); i += 2) {
                cout << a[i] + 1 << " " << a[i + 1] + 1 << '\n';
            }
            if ((int)a.size() % 2) {
                return a.back();
            }
            return -1;
        }
        map<int, vector<int>> mp;
        for (int i : a) {
            mp[p[i][d]].emplace_back(i);
        }
        int b = -1;
        for (auto [k, v] : mp) {
            int c = self(self, v, d + 1);
            if (c != -1) {
                if (b != -1) {
                    cout << b + 1 << " " << c + 1 << '\n';
                    b = -1;
                } else {
                    b = c;
                }
            }
        }
        return b;
    };
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    solve(solve, a, 0);
    return 0;
}