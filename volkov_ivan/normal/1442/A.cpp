#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int neg = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= a[i + 1]) neg += a[i] - a[i + 1];
        if (neg > a[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}