#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long sum = 0;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
            sum += i;
        }

        if (sum % n > 0) {
            cout << -1 << "\n";
        } else {
            sum /= n;
            int ans = 0;
            for (auto i : a) {
                ans += i > sum;
            }
            cout << ans << "\n";
        }
    }
}