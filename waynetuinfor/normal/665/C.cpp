#include <bits/stdc++.h>
using namespace std;

char cal(char a, char b) {
    if ('a' != a && 'a' != b) return 'a';
    if ('b' != a && 'b' != b) return 'b';
    if ('c' != a && 'c' != b) return 'c';
}

int main() {
    string s; cin >> s;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            if (i + 1 < s.length()) s[i] = cal(s[i - 1], s[i + 1]);
            else s[i] = cal(s[i - 1], s[i - 1]);
        }
    }
    cout << s << endl;
}