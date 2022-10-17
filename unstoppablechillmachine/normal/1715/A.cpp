#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1) {
            cout << 0 << '\n';
            continue;
        }
        cout << 2 * (n + m - 2) - max(n, m) + 2 << '\n';
    }
    return 0;
}