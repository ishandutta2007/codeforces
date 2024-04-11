#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int tt;
    cin >> tt;
    rep(qq, 0, tt) {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        int ans = 0;
        rep(i, 0, p + 1) rep(j, 0, f + 1) {
            if (2 * i + 2 * j <= b)
                ans = max(ans, h * i + c * j);
        }
        cout << ans << endl;
    }

    return 0;
}