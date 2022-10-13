#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int m, n; cin >> m >> n;
        vector<vector<int>> p(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> p[i][j];
            }
        }
        vector<int> f(n);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (p[i][j] > p[f[j]][j]) {
                    f[j] = i;
                }
            }
        }
        vector<int> mx(n);
        for (int i = 0; i < n; i++) {
            mx[i] = p[f[i]][i];
        }
        sort(f.begin(), f.end());
        bool same = false;
        for (int i = 1; i < n; i++) {
            if (f[i] == f[i - 1]) {
                same = true;
            }
        }
        if (same) {
            cout << *min_element(mx.begin(), mx.end()) << "\n";
        } else {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int curr = 0;
                    for (int put = 0; put < m; put++) {
                        curr = max(curr, min(p[put][i], p[put][j]));
                    }
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j)
                            curr = min(curr, mx[k]);
                    }
                    ans = max(ans, curr);
                }
            }
            cout << ans << "\n";
        }
    }
}