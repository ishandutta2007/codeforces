#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        int res = (n * m + 1) / 2;
        cout << res << endl;
    }
}