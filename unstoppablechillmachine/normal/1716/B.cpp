#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        for (int pos = n - 1; pos >= 1; pos--) {
            for (int i = 1; i < pos; i++) {
                cout << i << ' ';
            }
            cout << n << ' ';
            for (int i = pos + 1; i <= n; i++) {
                cout << i - 1 << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}