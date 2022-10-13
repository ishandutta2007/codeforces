#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        int mn = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] < a[mn]) mn = i;
            if(a[i] > a[mx]) mx = i;
        }
        int ans = min(max(mn, mx) + 1, n - min(mn, mx));
        ans = min(ans, mn + 1 + n - mx);
        ans = min(ans, mx + 1 + n - mn);
        cout << ans << "\n";
    }
}