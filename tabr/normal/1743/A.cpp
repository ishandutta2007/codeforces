#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        rep(i, n) {
            int a;
            cin >> a;
        }
        n = 10 - n;
        cout << n * (n - 1) / 2 * 6 << endl;
    }
    return 0;
}