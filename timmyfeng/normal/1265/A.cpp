#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                set<char> c = {'a', 'b', 'c'};
                if (i) {
                    c.erase(s[i - 1]);
                }
                if (i + 1 < s.size()) {
                    c.erase(s[i + 1]);
                }
                s[i] = *c.begin();
            } else {
                if (i + 1 < s.size() && s[i] == s[i + 1]) {
                    s = "-1";
                    break;
                }
            }
        }
        cout << s << '\n';
    }
}