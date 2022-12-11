#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int maxi = 1;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cur = 2;
            for (int t = j + 1; t < n; t++) {
                if ((a[j] - a[i]) * (t - i) + a[i] * (j - i) == a[t] * (j - i))
                    cur++;
            }
            maxi = max(maxi, cur);
        }
    }
    cout << n - maxi << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}