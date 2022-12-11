#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    int a = 6, b = 10, c = 14, d = 15;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n <= a + b + c) {
            cout << "NO\n";
            continue;
        }
        int rest = n - a - b - c;
        int ans1 = a, ans2 = b, ans3 = c, ans4 = rest;
        if (rest == a || rest == b || rest == c) {
            ans4--; 
            ans3 = d;
        }
        cout << "YES\n";
        cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << "\n";
    }
}