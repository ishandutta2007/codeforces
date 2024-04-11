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
        vector<int> a(n), l(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (!l[i]) {
                b.emplace_back(a[i]);
            }
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            if (!l[i]) {
                a[i] = b.back();
                b.pop_back();
            }
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}