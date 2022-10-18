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
        int b = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            while (a[i] % 2 == 0) {
                a[i] /= 2;
                b++;
            }
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < b; i++) {
            a.back() *= 2;
        }
        cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
    }
    return 0;
}