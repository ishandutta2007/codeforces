#include <bits/stdc++.h>
using namespace std;

const int N = 100;

bool used[N][N];
int a[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                used[i][j] = false;
            }
        }

        for (int i = 0; i < m; ++i) {
            int x = INT_MAX, r = -1, c = -1;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (!used[j][k] && a[j][k] < x) {
                        x = a[j][k], r = j, c = k;
                    }
                }
            }
            swap(a[r][c], a[r][i]);
            used[r][i] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}