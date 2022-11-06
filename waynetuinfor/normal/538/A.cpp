#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    string t = "CODEFORCES";
    int l = 0, r = t.length() - 1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == t[l]) ++l;
        else break;
    }
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == t[r]) --r;
        else break;
    }
    cout << (r < l ? "YES\n" : "NO\n");
    return 0;
}