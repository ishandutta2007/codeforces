#include <bits/stdc++.h>
using namespace std;

const int N = 500;

long long matrix[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                cin >> matrix[i][j];
            }
        }

        long long ans = min({
            matrix[n][0], matrix[n][n - 1], matrix[2 * n - 1][0], matrix[2 * n - 1][n - 1],
            matrix[0][n], matrix[n - 1][n], matrix[0][2 * n - 1], matrix[n - 1][2 * n - 1]
        });

        for (int i = n; i < 2 * n; i++) {
            for (int j = n; j < 2 * n; j++) {
                ans += matrix[i][j];
            }
        }

        cout << ans << "\n";
    }
}