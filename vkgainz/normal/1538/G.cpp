#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int find(int a, int b, int x, int y, int x1) {
    //ax1 + bx2 <= x
    //bx1 + ax2 <= y
    if(x1 < 0) return 0;
    if(a * 1LL * x1 > x || b * 1LL * x1 > y) return 0;
    return x1 + min((x - a * 1LL * x1) / b, (y - b * 1LL * x1) / a);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        int ans = 0;
        ans = max(ans, find(a, b, x, y, 0));
        ans = max(ans, find(a, b, x, y, min(x / a, y / b)));
        if(a != b) {
            int lim = (b * 1LL * y - a * 1LL * x) / (b * 1LL * b - a * 1LL * a);
            ans = max(ans, find(a, b, x, y, lim - 1));
            ans = max(ans, find(a, b, x, y, lim));
            ans = max(ans, find(a, b, x, y, lim + 1));
        }
        cout << ans << "\n";
    }
}