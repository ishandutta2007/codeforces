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
    int tt;
    cin >> tt;
    while (tt--) {
        int x;
        cin >> x;
        vector<int> a(3);
        x--;
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
            a[i]--;
        }
        if (a[x] == -1 || a[a[x]] == -1) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}