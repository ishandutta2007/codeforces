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
        int n, x;
        cin >> n >> x;
        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        sort(w.begin(), w.end());
        if (accumulate(w.begin(), w.end(), 0) == x) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += w[i];
            if (x == s) {
                swap(w[i], w[i + 1]);
                break;
            }
        }
        for (int i : w) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}