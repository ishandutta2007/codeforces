#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> f(101);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ++f[abs(a[i])];
        }
        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            if (i == 0) {
                ans += min(f[i], 1);
                continue;
            }
            if (f[i] >= 2) 
                ans += 2;
            else
                ans += f[i];
        }
        cout << ans << "\n";
    }
}