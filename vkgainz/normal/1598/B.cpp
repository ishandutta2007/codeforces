#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
        bool work = false;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                int x = 0, y = 0, z = 0;
                for (int k = 0; k < n; k++) {
                    if (a[k][i] and a[k][j]) ++z;
                    else if (a[k][i]) ++x;
                    else if (a[k][j]) ++y;
                }
                if (x + y + z == n and x <= n / 2 and y <= n / 2
                        and n % 2 == 0) {
                    work = true;
                }
            }
        }
        if (work) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}