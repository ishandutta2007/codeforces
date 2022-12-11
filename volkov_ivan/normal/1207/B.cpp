#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    vector <pair <int, int>> res;
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
                b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
                res.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << res.size() << endl;
    for (auto elem : res) cout << elem.first + 1 << ' ' << elem.second + 1 << endl;
    return 0;
}