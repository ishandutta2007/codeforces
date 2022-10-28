#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int perm[N], ans[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
    }

    for (int i = 0; i < n; ++i) {
        int r = i, c = i;
        for (int j = 0; j < perm[i]; ++j) {
            ans[r][c] = perm[i];
            if (c > 0 && ans[r][c - 1] == 0) {
                --c;
            } else {
                ++r;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}