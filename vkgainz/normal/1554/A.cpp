#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = 0LL;
        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, a[i] * 1LL * a[i + 1]);
        }
        cout << ans << "\n";
    }
}