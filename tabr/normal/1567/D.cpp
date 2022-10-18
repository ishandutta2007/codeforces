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
        long long s;
        cin >> s;
        int n;
        cin >> n;
        vector<long long> a;
        for (int i = (int) 1e9; i >= 1; i /= 10) {
            while (s >= i) {
                a.emplace_back(i);
                s -= i;
            }
        }
        while ((int) a.size() < n) {
            for (int i = (int) a.size() - 1; i >= 0; i--) {
                if (a[i] > 1) {
                    for (int j = 0; j < 10; j++) {
                        a.emplace_back(a[i] / 10);
                    }
                    a.erase(a.begin() + i);
                    break;
                }
            }
            sort(a.rbegin(), a.rend());
        }
        for (int i = 0; i < n - 1; i++) {
            cout << a[i] << " ";
        }
        long long b = 0;
        for (int i = n - 1; i < (int) a.size(); i++) {
            b += a[i];
        }
        cout << b << '\n';
    }
    return 0;
}