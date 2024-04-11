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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a + b + c + d == 0) {
            cout << 0 << '\n';
        } else if (a + b + c + d == 4) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}