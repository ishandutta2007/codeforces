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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<int> a(3), b(3);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 'O') {
                    a[(i + n - j) % 3]++;
                } else if (s[i][j] == 'X') {
                    b[(i + n - j) % 3]++;
                }
            }
        }
        int x = 0, y = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) {
                    continue;
                }
                if (a[i] + b[j] < a[x] + b[y]) {
                    x = i;
                    y = j;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + n - j) % 3 == x && s[i][j] == 'O') {
                    s[i][j] = 'X';
                }
                if ((i + n - j) % 3 == y && s[i][j] == 'X') {
                    s[i][j] = 'O';
                }
            }
            cout << s[i] << '\n';
        }
    }
    return 0;
}