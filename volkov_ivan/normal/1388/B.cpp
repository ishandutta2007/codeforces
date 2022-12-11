#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int cnt = (3 * n) / 4;
        for (int j = 0; j < n; j++) {
            if (j < cnt) cout << "9";
            else cout << "8";
        }
        cout << "\n";
    }
}