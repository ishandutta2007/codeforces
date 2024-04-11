#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        string a;
        cin >> a;
        int zero = 0;
        int even = 0;
        int sum = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == '0') {
                zero++;
            }
            if ((a[i] - '0') % 2 == 0) {
                even++;
            }
            sum += a[i] - '0';
        }
        if (sum % 3 != 0 || zero == 0 || even < 2) {
            cout << "cyan" << '\n';
            continue;
        }
        cout << "red" << '\n';
    }
    return 0;
}