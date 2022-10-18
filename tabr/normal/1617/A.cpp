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
        string s, t;
        cin >> s >> t;
        sort(s.begin(), s.end());
        if (t == "abc" && s.find('a') != string::npos && s.find('b') != string::npos && s.find('c') != string::npos) {
            for (int i = 0; i < (int) s.size(); i++) {
                if (s[i] == 'b' || s[i] == 'c') {
                    s[i] ^= 'b' ^ 'c';
                }
            }
            sort(s.begin(), s.end());
            for (int i = 0; i < (int) s.size(); i++) {
                if (s[i] == 'b' || s[i] == 'c') {
                    s[i] ^= 'b' ^ 'c';
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}