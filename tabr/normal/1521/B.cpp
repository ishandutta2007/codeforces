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
        int id = (int)(min_element(a.begin(), a.end()) - a.begin());
        cout << n - 1 << '\n';
        for (int i = id - 1; i >= 0; i--) {
            cout << id + 1 << " " << i + 1 << " " << a[id] << " " << a[id] + id - i << '\n';
        }
        for (int i = id + 1; i < n; i++) {
            cout << id + 1 << " " << i + 1 << " " << a[id] << " " << a[id] + i - id << '\n';
        }
    }
    return 0;
}