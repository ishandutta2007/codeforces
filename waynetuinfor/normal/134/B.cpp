#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
    int ans = 0;
    while (a != b && max(a, b) > 1) {
        if (a > b) swap(a, b);
        ans += b / a;
        b %= a;
        if (b == 0) b += a, --ans;
    }
    if (a == b && a != 1) return 1e9;
    return ans;
}

int main() {
    int n; cin >> n;
    if (n == 1) return cout << 0 << endl, 0;
    int ans = n + 1;
    for (int i = 1; i < n; ++i) ans = min(ans, solve(n, i));
    cout << ans << endl;
    return 0;
}