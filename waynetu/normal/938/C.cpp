#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t; while (t--) {
        int x; cin >> x;
        if (x == 0) {
            cout << "1 1" << endl;
            continue;
        }
        bool ans = false;
        for (int i = 1; i * i <= x && !ans; ++i) if (x % i == 0) {
            if ((x / i + i) % 2 == 0) {
                int a = (x / i + i) / 2;
                int b = x / i - a;
                if (a < b) swap(a, b);
                if (b == 0) continue;
                for (int j = (a + 1) / (b + 1); j <= (a + 1) / b && !ans; ++j) {
                    if (ceil(1.0 * (a - j + 1) / j) == b) cout << a << ' ' << j << endl, ans = true;
                }
            }
        }
        if (!ans) cout << "-1" << endl;
    }
}