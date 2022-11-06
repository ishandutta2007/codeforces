#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int c = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') ++c;
    }
    if (c == s.size() || c == s.size() - 1 && s[0] >= 'a' && s[0] <= 'z') {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
            else s[i] = s[i] - 'a' + 'A';
        }
    }
    cout << s << endl;
}