#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        int n = a + b;

        bool palindrome = true;
        for (int i = 0; i < n / 2; ++i) {
            palindrome &= s[i] == '?' || s[n - 1 - i] == '?' || s[i] == s[n - 1 - i];
        }

        if (!palindrome) {
            cout << -1 << "\n";
            continue;
        }

        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == '0' || s[n - 1 - i] == '0') {
                s[i] = s[n - 1 - i] = '0';
                a -= 2;
            } else if (s[i] == '1' || s[n - 1 - i] == '1') {
                s[i] = s[n - 1 - i] = '1';
                b -= 2;
            }
        }

        if (n % 2 == 1) {
            if (s[n / 2] == '?') {
                if (a % 2 == 0) {
                    s[n / 2] = '1';
                } else {
                    s[n / 2] = '0';
                }
            }
            --(s[n / 2] == '0' ? a : b);
        }

        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == '?') {
                if (a > 0) {
                    s[i] = s[n - 1 - i] = '0';
                    a -= 2;
                } else {
                    s[i] = s[n - 1 - i] = '1';
                    b -= 2;
                }
            }
        }

        if (a == 0 && b == 0) {
            cout << s << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}