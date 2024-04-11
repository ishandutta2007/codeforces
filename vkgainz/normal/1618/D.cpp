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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n - 2 * k; i++) {
            ans += a[i];
        }
        int mx = 0, lst = a[n - 2 * k], curr = 0;
        for (int i = n - 2 * k; i < n; i++) {
            if (a[i] == lst) {
                ++curr;
                mx = max(mx, curr);
            } else {
                curr = 1;
                mx = max(mx, 1);
                lst = a[i];
            }
        }
        if (mx > k) {
            cout << ans + mx - k << "\n";
        } else {
            cout << ans << "\n";
        }
    }
}