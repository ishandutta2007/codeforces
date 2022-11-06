#include <bits/stdc++.h>
using namespace std;

const string k = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    char c; cin >> c;
    string s; cin >> s;
    if (c == 'R') {
        for (int i = 0; i < s.length(); ++i) {
            int pos = -1;
            for (int j = 0; j < k.length(); ++j) if (s[i] == k[j]) {
                pos = j; break;
            }
            cout << k[pos - 1];
        }
        cout << endl;
    } else {
        for (int i = 0; i < s.length(); ++i) {
            int pos = -1;
            for (int j = 0; j < k.length(); ++j) if (s[i] == k[j]) {
                pos = j; break;
            }
            cout << k[pos + 1];
        }
        cout << endl;
    }
    return 0;
}