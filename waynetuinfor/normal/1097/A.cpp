#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    for (int i = 0; i < 5; ++i) {
        string t; cin >> t;
        if (s[0] == t[0] || s[1] == t[1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}