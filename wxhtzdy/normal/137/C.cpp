#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int ans = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second >= mx) {
            mx = a[i].second;
        } else {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}