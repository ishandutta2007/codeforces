#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int num = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                num ^= 1;
            }
        }
        if (num == 1) {
            cout << s << "\n";
        } else {
            string t;
            if (s[0] == 'a') {
                t += 'b';
            } else {
                t += 'a';
            }
            t += s.substr(1, s.length() - 1);
            cout << t << "\n";
        }
    }
}