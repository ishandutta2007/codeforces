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
        int n;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        cout << (max_element(c.begin(), c.end()) - c.begin() + 1) << '\n';
    }
    return 0;
}