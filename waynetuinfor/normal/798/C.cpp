#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int gcd = 0;
    for (int i = 0; i < n; ++i) gcd = __gcd(gcd, a[i]);
    if (gcd != 1) return cout << "YES\n0\n", 0;
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        while (a[i] & 1) {
            int x = a[i] - a[i + 1], y = a[i] + a[i + 1];
            a[i] = x, a[i + 1] = y;
            ++ans;
        }
    }
    if (a[n - 1] & 1) ans += 2;
    cout << "YES\n" << ans << '\n';
    return 0;
}