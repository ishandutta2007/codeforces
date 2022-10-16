#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int l = 1, r = n - 1;

    while (l != r) {
        const int m = (l + r + 1) / 2;
        const int k = n - m % n;

        cout << "+ " << k << endl;

        int t; cin >> t;
        if (t == (m + k) / n) {
            l = m;
        } else {
            r = m - 1;
        }

        l += k;
        r += k;
    }

    cout << "! " << r << endl;

}