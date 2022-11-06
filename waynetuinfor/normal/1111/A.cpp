#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string t; cin >> t;
    if ((int)s.size() != (int)t.size()) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            s[i] = 'a';
        else
            s[i] = 'b';
    }
    for (int i = 0; i < s.size(); ++i) {
        if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u')
            t[i] = 'a';
        else
            t[i] = 'b';
    }
    cout << (s == t ? "Yes" : "No") << endl;
}