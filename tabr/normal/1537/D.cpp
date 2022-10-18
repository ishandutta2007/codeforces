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
    vector<int> a(1, 2);
    while (4LL * a.back() < (int) 1e9) {
        a.emplace_back(a.back() * 4);
    }
    while (tt--) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << "Bob" << '\n';
        } else if (binary_search(a.begin(), a.end(), n)) {
            cout << "Bob" << '\n';
        } else {
            cout << "Alice" << '\n';
        }
        /*
        vector<int> a(n + 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j < i; j++) {
                if (i % j == 0 && a[i - j] == 0) {
                    a[i] = 1;
                }
            }
        }
        debug(a);
        for (int i = 2; i <= n; i++) {
            if (i % 2 == a[i]) {
                debug(i);
            }
        }
        */
    }
    return 0;
}