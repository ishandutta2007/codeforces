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
        int n; cin >> n;
        vector<int> a(n);
        long long sum = 0LL;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        long long ans = 0LL;
        long long k = sum / n;
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            if (2 * 1LL * sum % n == 0) {
                ans += freq[2 * 1LL * sum / n - a[i]];
                ++freq[a[i]];
            }
        }
        cout << ans << "\n";
    }
}