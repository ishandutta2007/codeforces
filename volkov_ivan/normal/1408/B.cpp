#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n]; 
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0 || a[i] != a[i - 1]) cnt++;
    }
    int m;
    if (k == 1 && cnt != 1) {
        cout << "-1\n";
        return;
    }
    m = 1;
    if (k != 1) {
        m = (cnt - 1 + (k - 2)) / (k - 1);
    }
    cout << max(1, m) << endl;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}