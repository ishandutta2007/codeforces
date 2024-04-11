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
        string s;
        cin >> n >> s;
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            int a = 0, b = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'a') {
                    a++;
                } else {
                    b++;
                }
                if (a == b) {
                    l = i + 1;
                    r = j + 1;
                }
            }
        }
        cout << l << " " << r << '\n';
    }
    return 0;
}