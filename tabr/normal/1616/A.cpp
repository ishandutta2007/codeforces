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
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            if (a[i - 1] == a[i]) {
                a[i] = -a[i];
            }
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        cout << a.size() << '\n';
    }
    return 0;
}