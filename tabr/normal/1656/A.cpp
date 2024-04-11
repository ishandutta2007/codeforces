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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int x = (int) (min_element(a.begin(), a.end()) - a.begin());
        int y = (int) (max_element(a.begin(), a.end()) - a.begin());
        cout << x + 1 << " " << y + 1 << '\n';
    }
    return 0;
}