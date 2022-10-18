#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        string s(m, '0');
        s[i] = '1';
        cout << "? " << s << endl;
        cin >> a[i];
    }
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    string t(m, '0');
    int ans = 0;
    for (int i : order) {
        string x = t;
        x[i] = '1';
        cout << "? " << x << endl;
        int y;
        cin >> y;
        if (y == ans + a[i]) {
            ans = y;
            t = x;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}