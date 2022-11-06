#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
multiset<char> ms;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    for (int i = 0; i < t.length(); ++i) ms.insert(t[i]);
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (ms.find(s[i]) != ms.end()) {
            ms.erase(ms.find(s[i])); s[i] = '.';
            ++a;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '.') continue;
        if (s[i] >= 'A') if (ms.find(s[i] + 32) != ms.end()) ++b, ms.erase(ms.find(s[i] + 32)), s[i] = '.';
        else if (ms.find(s[i] - 32) != ms.end()) ++b, ms.erase(ms.find(s[i] - 32)), s[i] = '.';
    }
    cout << a << ' ' << b << endl;
    return 0;  
}