#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; i++) {
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        int res = r % 2 + b % 2 + g % 2 + w % 2;
        if (res <= 1) {
            cout << "Yes" << endl;
            continue;
        }
        if (r > 0 && g > 0 && b > 0) r--, g--, b--, w += 3;
        res = r % 2 + b % 2 + g % 2 + w % 2;
        cout << (res <= 1 ? "Yes" : "No") << endl;
    }
    return 0;
}