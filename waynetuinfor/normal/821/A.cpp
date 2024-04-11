#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 10;
int grid[maxn][maxn];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> grid[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (grid[i][j] != 1) {
            bool ok = false;
            for (int s = 0; s < n; ++s) for (int t = 0; t < n; ++t) {
                if (grid[i][s] + grid[t][j] == grid[i][j]) ok = true;
            }
            if (!ok) return cout << "No\n", 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}