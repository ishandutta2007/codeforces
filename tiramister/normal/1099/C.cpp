#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    int q = count(s.begin(), s.end(), '?');
    int a = count(s.begin(), s.end(), '*');

    if (n - (q + a) * 2 > k) {
        cout << "Impossible" << endl;
        return 0;
    }

    s.push_back('$');
    if (a > 0) {
        bool fa = false;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '?' || s[i] == '*') continue;
            if (s[i + 1] == '?' || (s[i + 1] == '*' && fa)) continue;

            if (s[i + 1] == '*') {
                int r = k - (n - (q + a) * 2);
                for (int j = 0; j < r; ++j) {
                    cout << s[i];
                }
                fa = true;
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    } else {
        if (n - q < k) {
            cout << "Impossible" << endl;
            return 0;
        }

        int r = k - (n - q * 2);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') continue;
            if (s[i + 1] == '?' && r == 0) continue;

            if (s[i + 1] == '?') {
                --r;
            }
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}