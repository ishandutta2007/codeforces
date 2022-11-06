#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int k = 0; k <= 10000; ++k) {
        bool b = false;
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            if (k - a[i] < 0) b = true;
            x += a[i], y += k - a[i];
        }
        if (b) continue;
        if (y > x) {
            cout << k << endl;
            return 0;
        }
    }
}