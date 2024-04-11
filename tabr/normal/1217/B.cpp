#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int mx = 0;
        int dif = -1e9;
        rep(i, 0, n) {
            int d, h;
            cin >> d >> h;
            dif = max(dif, d - h);
            mx = max(mx, d);
        }
        if (mx >= x)
            cout << 1 << endl;
        else if (dif <= 0)
            cout << -1 << endl;
        else
            cout << 1 + (x - mx + dif - 1) / dif << endl;
    }

    return 0;
}