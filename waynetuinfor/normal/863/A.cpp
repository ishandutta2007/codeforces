#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int ind = s.length() - 1, c = 0;
    while (ind >= 0 && s[ind] == '0') --ind, ++c;
    string t = "";
    for (int i = 0; i < c; ++i) t += '0';
    for (int i = 0; i < s.length(); ++i) t += s[i];
    string k = t;
    reverse(k.begin(), k.end());
    cout << (k == t ? "YES" : "NO") << endl;
    return 0;
}