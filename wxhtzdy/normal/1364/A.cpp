#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int sum = accumulate(a.begin(), a.end(), 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % x != 0) {
                break;
            }
            cnt++;
        }
        int cnt1 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] % x != 0) {
                break;
            }
            cnt1++;
        }
        if (sum % x != 0) {
            cout << n << '\n';
        }else{
            int ans = n - min(cnt + 1, cnt1 + 1);
            if (ans == 0) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }
    return 0;
}