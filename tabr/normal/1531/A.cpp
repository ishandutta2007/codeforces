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
    int n;
    cin >> n;
    string s = "blue";
    int lock = 0;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if (t == "lock") {
            lock = 1;
        } else if (t == "unlock") {
            lock = 0;
        } else if (!lock) {
            s = t;
        }
    }
    cout << s << '\n';
    return 0;
}