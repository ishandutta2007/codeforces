#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> a(100), b(100);
    b[0] = (1 << 14) - (1 << 7);
    rep(i, 1, 100) {
        a[i] = a[i - 1] + 1;
        b[i] = b[i - 1] - (1 << 7);
    }

    cout << "? ";
    rep(i, 0, 100) cout << a[i] << ' ';
    cout << endl << flush;
    int x1;
    cin >> x1;

    cout << "? ";
    rep(i, 0, 100) cout << b[i] << ' ';
    cout << endl << flush;
    int x2;
    cin >> x2;

    int ans = x2 & ((1 << 7) - 1);
    ans += x1 & ((1 << 14) - (1 << 7));
    cout << "! " << ans << endl;
    return 0;
}