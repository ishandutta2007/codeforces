#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << 1 << ' ' << 1 << endl << -a[0] << endl;
    if (n == 1) {
        cout << 1 << ' ' << 1 << endl << 0 << endl;
        cout << 1 << ' ' << 1 << endl << 0 << endl;
        return 0;
    }
    cout << 2 << ' ' << n << endl;
    //int xx, yy;
    //gcd(n - 1, n, xx, yy);
    //int xx = -1, yy = 1;
    for (int i = 1; i < n; i++) cout << a[i] * (n - 1) << ' ';
    cout << endl;
    cout << 1 << ' ' << n << endl;
    cout << 0 << ' ';
    for (int i = 1; i < n; i++) cout << -a[i] * n << ' ';
    cout << endl;
    return 0;
}