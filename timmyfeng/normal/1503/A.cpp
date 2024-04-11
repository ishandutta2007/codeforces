#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int one = count(s.begin(), s.end(), '1');
        if (one % 2 == 1 || s[0] == '0' || s[n - 1] == '0') {
            cout << "NO\n";
        } else {
            one /= 2;
            string a, b;
            bool zero = false;
            for (auto c : s) {
                if (c == '1') {
                    if (--one < 0) {
                        a += ')', b += ')';
                    } else {
                        a += '(', b += '(';
                    }
                } else {
                    a += !zero ? '(' : ')';
                    b += zero ? '(' : ')';
                    zero ^= true;
                }
            }

            cout << "YES\n";
            cout << a << "\n";
            cout << b << "\n";
        }
    }
}