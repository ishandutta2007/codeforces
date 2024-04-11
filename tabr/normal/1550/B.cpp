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
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int c = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                c++;
            }
        }
        if (b < 0) {
            c = (c + 2) / 2;
        } else {
            c = n;
        }
        cout << n * a + c * b << '\n';
    }
    return 0;
}