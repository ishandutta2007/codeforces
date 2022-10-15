#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        while (n) {
            int take = 0;
            for (int x = n, p = 1; x > 0; x /= 10, p *= 10) {
                take += p * !!(x % 10);
            }
            n -= take;
            ++ans;
        }
        cout << ans << '\n';
    }
    exit(0);
}