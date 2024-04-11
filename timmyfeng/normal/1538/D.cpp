#include <bits/stdc++.h>
using namespace std;

int factors(int n) {
    int ans = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            ++ans;
        }
    }
    ans += n > 1;
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;

        int g = gcd(a, b);

        cout << ((a > g) + (b > g) <= k && k <= factors(a) + factors(b) && (a != b || k > 1) ? "Yes" : "No") << "\n";
    }
}