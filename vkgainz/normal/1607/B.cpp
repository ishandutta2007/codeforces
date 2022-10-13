#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long x_0; cin >> x_0;
        long long n; cin >> n;
        long long lst = n - (n % 4) - 1;
        long long ans = 0LL;
        ans = (lst + 1);
        for (long long j = lst + 1; j <= n; j++) {
            if (j <= lst + 2) ans -= j;
            else ans += j;
        }
        if (x_0 % 2 == 0) {
            ans += x_0;
        } else {
            ans = -ans + x_0;
        }
        cout << ans << "\n";
    }
}