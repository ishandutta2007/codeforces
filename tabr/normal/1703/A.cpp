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
        string s;
        cin >> s;
        for (int i = 0; i < 3; i++) {
            s[i] = toupper(s[i]);
        }
        if (s != "YES") {
            s = "NO";
        }
        cout << s << '\n';
    }
    return 0;
}