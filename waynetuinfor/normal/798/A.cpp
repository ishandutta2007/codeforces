#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        for (char j = 'a'; j <= 'z'; ++j) if (j != c) {
            s[i] = j;
            string t = s; reverse(t.begin(), t.end());
            if (t == s) return cout << "YES\n", 0;
        }
        s[i] = c;
    }
    cout << "NO\n";
    return 0;
}