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
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[-a[i]]++;
        }
        int ones = 0;
        int many = 0;
        for (auto [x, y] : cnt) {
            if (y > 1) {
                many++;
            } else {
                ones++;
            }
        }
        cout << many + (ones + 1) / 2 << '\n';
    }
    return 0;
}