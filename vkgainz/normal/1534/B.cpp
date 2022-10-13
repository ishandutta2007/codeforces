#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a;
        a.push_back(0);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push_back(x);
        }
        a.push_back(0);
        long long ans = 0LL;
        for(int i = 1; i <= n; i++) {
            if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ans += a[i] - max(a[i - 1], a[i + 1]);
                a[i] = max(a[i - 1], a[i + 1]);
            }
        }
        for(int i = 0; i <= n; i++) {
            ans += abs(a[i] - a[i + 1]);
        }
        cout << ans << "\n";
    }
}