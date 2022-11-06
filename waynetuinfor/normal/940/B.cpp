#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a, b; cin >> n >> k >> a >> b;
    if (k == 1) return cout << a * 1ll * (n - 1) << endl, 0;
    long long ans = 0;
    while (n > 1) {
        if (n % k == 0) {
            ans += min(a * 1ll * (n - n / k), 1ll * b);
            n /= k;
            continue;
        } 
        int to = max(1, (n / k) * k);
        ans += a * 1ll * (n - to);
        n = to;
    }
    cout << ans << endl;
}