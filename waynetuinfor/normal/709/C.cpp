#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) if (s[i] != 'a') {
        for (int j = i; j < s.length(); ++j) {
            if (s[j] != 'a') --s[j];
            else break;
        }
        cout << s << endl;
        return 0;
    }
    s[s.length() - 1] = 'z';
    cout << s << endl;
    return 0;
}