#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<bool> used(26);
        vector<char> kb(52);
        bool ok = true;
        int ndx = 26;
        for (char c : s) {
            if (kb[ndx] == 0) {
                kb[ndx] = c;
            } else if (ndx > 0 && kb[ndx - 1] == c) {
                ndx--;
            } else if (ndx < 52 && kb[ndx + 1] == c) {
                ndx++;
            } else if (!used[c - 'a'] && ndx > 0 && kb[ndx - 1] == 0) {
                ndx--;
                kb[ndx] = c;
            } else if (!used[c - 'a'] && ndx < 52 && kb[ndx + 1] == 0) {
                ndx++;
                kb[ndx] = c;
            } else {
                ok = false;
                break;
            }
            used[c - 'a'] = true;
        }
        if (ok) {
            cout << "YES\n";
            for (char c : kb) {
                if (c) {
                    cout << c;
                }
            }
            for (int i = 0; i < 26; i++) {
                if (!used[i]) {
                    cout << (char)('a' + i);
                }
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}