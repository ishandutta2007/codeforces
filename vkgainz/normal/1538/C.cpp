#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, l, r; cin >> n >> l >> r;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long ans = 0LL;
        for(int i = 1; i < n; i++) {
            if(a[i] + a[0] > r) continue;
            if(a[i] + a[i - 1] < l) continue;
            int lo = 0, hi = i - 1;
            for(int j = 0; j < 20; j++) {
                int mid = (lo + hi) / 2;
                if(a[i] + a[mid] >= l)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            int lo2 = 0, hi2 = i - 1;
            for(int j = 0; j < 20; j++) {
                int mid = (lo2 + hi2 + 1) / 2;
                if(a[i] + a[mid] <= r) {
                    lo2 = mid;
                }
                else 
                    hi2 = mid - 1;
            }
            ans += max(0, lo2 - lo + 1);
        }
        cout << ans << "\n";
    }
}