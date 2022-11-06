#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, s; cin >> n >> s;
    int ans = 0;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if (s * 100 >= x * 100 + y) ans = max(ans, (s * 100 - x * 100 - y) % 100), ok = true;
    }
    if (ok) cout << ans << '\n';
    else cout << "-1\n";
    return 0;
}