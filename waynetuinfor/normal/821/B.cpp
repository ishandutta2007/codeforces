#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, b; cin >> m >> b;
    long long ans = 0;
    for (int y = 0; y <= b; ++y) {
        long long x = b * m - m * y;
        long long p = (long long)x * (long long)(x + 1) / 2 * (long long)(y + 1) + (long long)(x + 1) * (long long)(y) * (long long)(y + 1) / 2;
        ans = max(ans, p);
    }
    cout << ans << endl;
    return 0;
}