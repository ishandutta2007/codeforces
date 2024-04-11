#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        int maxi, mini;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0) {
                maxi = mini = a[i];
            }
            maxi = max(maxi, a[i]);
            mini = min(mini, a[i]);
        }
        for (int i = 0; i < n; i++) a[i] = maxi - a[i];
        int s = maxi - mini;
        k--;
        if (k % 2 == 0) {
            for (int i = 0; i < n; i++) cout << a[i] << ' ';
        } else {
            for (int i = 0; i < n; i++) cout << s - a[i] << ' ';
        }
        cout << "\n";
    }
    return 0;
}