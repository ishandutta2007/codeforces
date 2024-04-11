#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = 1; a[n + 1] = 1000000;
    int ans = 1000000;
    for (int i = 0; i <= n; ++i) ans = min(ans, max(a[i] - 1, 1000000 - a[i + 1]));
    cout << ans << endl;
}