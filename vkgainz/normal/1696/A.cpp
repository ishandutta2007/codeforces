#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, z; cin >> n >> z;
        vector<int> a(n);
        int ans = z;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans = max(ans, a[i] | z);
        }
        cout << ans << "\n";
    }
}