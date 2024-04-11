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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < n; j++) {
            if (a[j] == t) {
                cout << j + 1 << " ";
                for (int k = j; k > 0; k--) {
                    a[k] = a[k - 1];
                }
                a[0] = t;
                break;
            }
        }
    }
    cout << '\n';
    return 0;
}