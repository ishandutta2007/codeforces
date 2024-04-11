#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if(sum % n)  {
            cout << -1 << "\n";
            continue;
        }
        int target = sum / n;
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = n - 1; i >=0; i--) {
            if(a[i] > target) continue;
            ans = n - i - 1;
            break;
        }
        cout << ans << "\n";
    }
}