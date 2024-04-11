#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        bool nondec = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0 && a[i] < a[i - 1]) {
                nondec = false;
            }
        }
        if (a[n - 2] <= a[n - 1]) {
            if (a[n - 1] < 0) {
                if (nondec) cout << 0 << "\n";
                else cout << -1 << "\n";
            } else {
                cout << n - 2 << "\n";
                for (int i = 0; i < n - 2; i++) {
                    cout << i + 1 << " " << n - 1 << " " << n << "\n";
                }
            }
        } else {
            cout << -1 << "\n";
        }
    }
}