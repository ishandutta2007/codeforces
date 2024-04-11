#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '0') {
            if (x) cout << "3 1" << endl;
            else cout << "1 1" << endl;
            x ^= 1;
        } else {
            cout << y + 1 << ' ' << 2 << endl;
            (y += 1) %= 4;
        }
    }
}