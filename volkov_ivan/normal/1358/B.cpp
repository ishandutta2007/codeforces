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
    for (int p = 0; p < t; p++) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int cur = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] <= i + 1) {
                cur = i + 2;
            }
        }
        cout << cur << "\n";
    }
}