#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, k;
    cin >> a >> b >> k;
    int n = a + b;

    if (a == 0 || b == 1) {
        if (k == 0) {
            cout << "Yes\n";
            cout << string(b, '1') << string(a, '0') << "\n";
            cout << string(b, '1') << string(a, '0') << "\n";
        } else {
            cout << "No\n";
        }
    } else if (k >= n - 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";

        string x(n, '0'), y(n, '0');
        x[n - 1 - k] = y[n - 1] = '1';
        --b;

        for (int i = 0; i < n && b > 0; ++i) {
            if (x[i] == '0' && y[i] == '0') {
                x[i] = y[i] = '1';
                --b;
            }
        }

        cout << x << "\n";
        cout << y << "\n";
    }
}