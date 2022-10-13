#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <map>

using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> x(k);
        for (int i = 0; i < k; i++) {
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        int sum = 0;
        int ans = 0;
        reverse(x.begin(), x.end());
        for (int j = 0; j < k; j++) {
            if (sum + (n - x[j]) < n) {
                sum += (n - x[j]);
                ans = j + 1;
            }
        }
        cout << ans << "\n";
    }
}