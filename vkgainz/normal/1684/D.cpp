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
        multiset<int> sto;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sto.insert(i + 1 + a[i]);
        }
        long long T = accumulate(a.begin(), a.end(), 0LL);
        long long sub = 0LL;
        long long ans = 1e18;
        for (int r = 0; r <= k; r++) {
            if (r > 0) {
                auto it = *sto.rbegin();
                sto.erase(sto.lower_bound(it));
                sub += it;
            }
            ans = min(ans, T + r * 1LL * (n + 1)
                    - r * 1LL * (r + 1) / 2 - sub);
        }
        cout << ans << "\n";
    }
}