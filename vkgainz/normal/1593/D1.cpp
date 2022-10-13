#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int ans = 0;
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            ans = __gcd(ans, abs(a[i] - a[i - 1]));
        }
        if (ans == 0) {
            cout << -1 << "\n";
        }
        else {
            cout << ans << "\n";
        }
    }
}