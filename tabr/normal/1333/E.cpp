#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    if (n < 3) {
        cout << -1 << '\n';
        return 0;
    } else if (n == 3) {
        cout << "5 7 8\n2 1 6\n3 9 4\n";
        return 0;
    } else if (n == 4) {
        cout << "4 3 6 12\n7 5 9 15\n14 1 11 10\n13 8 16 2\n";
        return 0;
    }
    vector<vector<int>> a = {{4, 3, 6, 12, -8},
                             {7, 5, 9, 15, -7},
                             {14, 1, 11, 10, -6},
                             {13, 8, 16, 2, -5},
                             {-1, 0, -2, -3, -4}};
    int mn = -9;
    for (int k = 6; k <= n; k++) {
        if (k % 2 == 0) {
            for (int i = 0; i < k - 1; i++) {
                a[i].emplace_back(mn);
                mn--;
            }
            vector<int> b;
            for (int i = 0; i < k; i++) {
                b.emplace_back(mn);
                mn--;
            }
            reverse(b.begin(), b.end());
            a.emplace_back(b);
        } else {
            vector<int> b;
            for (int i = 0; i < k; i++) {
                b.emplace_back(mn);
                mn--;
            }
            a.emplace_back(b);
            for (int i = k - 2; i >= 0; i--) {
                a[i].emplace_back(mn);
                mn--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] - mn << " ";
        }
        cout << '\n';
    }
    return 0;
}