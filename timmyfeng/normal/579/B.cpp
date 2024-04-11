#include <bits/stdc++.h>
using namespace std;

const int N = 800;

int mate[N], a[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < i; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        array<int, 3> duo = {0, 0, 0};
        for (int j = 0; j < 2 * n; ++j) {
            for (int k = 0; k < j; ++k) {
                if (mate[j] == 0 && mate[k] == 0) {
                    duo = max(duo, array<int, 3>{a[j][k], j, k});
                }
            }
        }

        mate[duo[1]] = duo[2] + 1;
        mate[duo[2]] = duo[1] + 1;
    }

    for (int i = 0; i < 2 * n; ++i) {
        cout << mate[i] << " ";
    }
    cout << "\n";
}