#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q; while (q--) {
        int n; cin >> n;
        if (n <= 3) cout << "-1" << endl;
        else if (n == 4) cout << "1" << endl;
        else if (n == 5) cout << "-1" << endl;
        else if (n == 6) cout << "1" << endl;
        else if (n == 7) cout << "-1" << endl;
        else if (n % 2 == 0) {
            int ans = 0;
            bool ok = true;
            while (n % 4) {
                if (n < 6) {
                    cout << "-1" << endl;
                    ok = false;
                    break;
                }
                n -= 6;
                ++ans;
            }
            if (ok) cout << ans + n / 4 << endl;
        } else {
            int ans = 1;
            n -= 9;
            bool ok = true;
            while (n % 4) {
                if (n < 6) {
                    cout << "-1" << endl;
                    ok = false;
                    break;
                }
                n -= 6;
                ++ans;
            }
            if (ok) cout << ans + n / 4 << endl;
        }
    }
    return 0;
}