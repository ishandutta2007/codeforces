#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        string s;
        cin >> s;
        string a, b;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                a.push_back('0');
            } else {
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                b.push_back('1');
            } else {
                break;
            }
        }
        if (a.size() + b.size() < n) {
            a.push_back('0');
        }
        cout << a + b << '\n';
    }
    return 0;
}