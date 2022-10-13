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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        int p = -1, s = -1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                p = i;
                break;
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] == a[i - 1]) {
                s = i;
                break;
            }
        }
        if (p == -1 || p == s) {
            cout << 0 << "\n";
        } else {
            cout << max(1, s - p - 1) << "\n";
        }
    }
}