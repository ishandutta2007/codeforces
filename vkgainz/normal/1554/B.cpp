#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = -1e18;
        for(int i = 0; i < n; i++) {
           int rem = (k * n) / (i + 1) + 20;
           for(int j = i - 1; j >= max(0, i - rem); j--) {
               ans = max(ans, (i + 1) * 1LL * (j + 1) - k * (a[i] | a[j]));
           }
        }
        cout << ans << "\n";
    }
}