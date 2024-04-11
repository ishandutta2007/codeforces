#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    m--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && a[i] <= k) {
            ans = min(ans, abs(i - m));
        }
    }
    cout << ans * 10 << '\n';
    return 0;
}