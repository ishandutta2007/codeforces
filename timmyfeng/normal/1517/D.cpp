#include <bits/stdc++.h>
using namespace std;

const int N = 500, K = 11;

int hori[N][N], vert[N][N], mini[K][N][N];

void set_min(int &a, int b) {
    if (a == 0 || a > b) {
        a = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cin >> hori[i][j];
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vert[i][j];
        }
    }

    if (k % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << -1 << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    for (int i = 0; i < k / 2; ++i) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (r < n - 1) {
                    set_min(mini[i + 1][r + 1][c], mini[i][r][c] + vert[r][c]);
                    set_min(mini[i + 1][r][c], mini[i][r + 1][c] + vert[r][c]);
                }

                if (c < m - 1) {
                    set_min(mini[i + 1][r][c + 1], mini[i][r][c] + hori[r][c]);
                    set_min(mini[i + 1][r][c], mini[i][r][c + 1] + hori[r][c]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << 2 * mini[k / 2][i][j] << " ";
        }
        cout << "\n";
    }
}