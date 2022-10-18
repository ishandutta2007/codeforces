#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int l = -1;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n - 1) if (abs(a[i] - a[i + 1]) > 1) {
            l = i + 1;
            break;
        }

        if (l != -1) {
            cout << "YES" << endl;
            cout << l << ' ' << l + 1 << endl;
        } else
            cout << "NO" << endl;
    }
    return 0;
}