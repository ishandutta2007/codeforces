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
    vector<vector<int>> x(n, vector<int>(n));
    for (int tt = 0; tt < n * n; tt++) {
        int a;
        cin >> a;
        vector<pair<int, int>> b(2, {-1, -1});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (x[i][j]) {
                    continue;
                }
                if ((i + j) % 2) {
                    b[0] = {i, j};
                } else {
                    b[1] = {i, j};
                }
            }
        }
        if (a == 1) {
            if (b[1].first != -1) {
                auto [i, j] = b[1];
                cout << 2 << " " << i + 1 << " " << j + 1 << endl;
                x[i][j] = 1;
            } else {
                auto [i, j] = b[0];
                cout << 3 << " " << i + 1 << " " << j + 1 << endl;
                x[i][j] = 1;
            }
        } else if (a == 2) {
            if (b[0].first != -1) {
                auto [i, j] = b[0];
                cout << 1 << " " << i + 1 << " " << j + 1 << endl;
                x[i][j] = 1;
            } else {
                auto [i, j] = b[1];
                cout << 3 << " " << i + 1 << " " << j + 1 << endl;
                x[i][j] = 1;
            }
        } else {
            if (b[0].first != -1) {
                auto [i, j] = b[0];
                cout << 1 << " " << i + 1 << " " << j + 1 << endl;
                x[i][j] = 1;
            } else {
                auto [i, j] = b[1];
                cout << 2 << " " << i + 1 << " " << j + 1 << endl;
                x[i][j] = 1;
            }
        }
    }
    return 0;
}