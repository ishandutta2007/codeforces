#include <bits/stdc++.h>
using namespace std;

int pow10(int n) {
    return n == 0 ? 1 : 10 * pow10(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int x = pow10(c - 1);
        while ((int) to_string(x).size() < min(a, b)) {
            x *= 3;
        }

        if (a < b) {
            cout << x << " " << pow10(b - 1) << "\n";
        } else {
            cout << pow10(a - 1) << " " << x << "\n";
        }
    }
}