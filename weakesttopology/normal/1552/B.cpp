#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<array<int, 5>> r(n);
        for (int i = 0; i < n; ++i) {
            bool good = true;
            for (int j = 0; j < 5; ++j) {
                cin >> r[i][j];
                if (r[i][j] >= 3) good = false;
            }
        }
        auto cmp = [&](int i, int j) {
            int w = 0;
            for (int k = 0; k < 5; ++k) {
                w += (r[i][k] < r[j][k]);
            }
            return w >= 3;
        };
        int best = 0;
        for (int i = 1; i < n; ++i) {
            if (cmp(i, best)) best = i;
        }
        bool good = true;
        for (int i = 0; i < n; ++i) {
            if (i == best) continue;
            if (not cmp(best, i)) {
                good = false;
            }
        }
        cout << (good ? best + 1 : -1) << '\n';
    }
    exit(0);
}