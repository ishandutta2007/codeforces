#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = n / m, y = n / m;
            if (i < n % m) ++x;
            if (j < n % m) ++y;
            if (((i + 1) * (i + 1) + (j + 1) * (j + 1)) % m == 0) ans += x * 1ll * y;
        }
    }
    cout << ans << endl;
}