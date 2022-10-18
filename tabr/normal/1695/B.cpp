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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n % 2 == 0) {
            int i = (int) (min_element(a.begin(), a.end()) - a.begin());
            if (i % 2 == 0) {
                cout << "Joe" << '\n';
            } else {
                cout << "Mike" << '\n';
            }
        } else {
            cout << "Mike" << '\n';
        }
    }
    return 0;
}