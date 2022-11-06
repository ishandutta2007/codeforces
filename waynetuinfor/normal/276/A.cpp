#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 1;
int main() {
    int n, k; cin >> n >> k;
    int ans = -inf;
    for (int i = 0; i < n; ++i) {
        int f, t; cin >> f >> t;
        if (t > k) ans = max(ans, f - (t - k));
        else ans = max(ans, f);
    }
    cout << ans << endl;
    return 0;
}