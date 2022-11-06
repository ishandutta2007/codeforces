#include <bits/stdc++.h>
using namespace std;

map<char, char> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    for (int i = 0; i < 26; ++i) {
        mp[s[i]] = t[i];
        mp[s[i] - 32] = t[i] - 32;
    }
    string k; cin >> k;
    for (int i = 0; i < k.length(); ++i) {
        if (isalpha(k[i])) cout << mp[k[i]];
        else cout << k[i];
    }
    cout << endl;
    return 0;
}