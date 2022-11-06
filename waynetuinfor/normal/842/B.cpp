#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int main() {
    int d, r; cin >> r >> d;
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int x, y, ri; cin >> x >> y >> ri;
        double dis = sqrt(x * x + y * y);
        if (2 * ri <= d && dis - ri >= r - d && dis + ri <= r) ++ans;
    }
    cout << ans << endl;
    return 0;
}