#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if ((y - x) % (a + b) == 0) {
            cout << (y - x) / (a + b) << endl;
        } else
            cout << -1 << endl;
    }
    return 0;
}