#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<bool> in(2);
        int f = s.length(), l = -1, num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                f = min(f, i);
                l = max(l, i);
                ++num;
            }
        }
        if (num == 0) cout << 0 << "\n";
        else {
            if (l - f + 1 == num) {
                cout << 1 << "\n";
            }
            else {
                cout << 2 << "\n";
            }
        }
    }
}