#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s, t, ans;
    cin >> s >> t;
    if (s[0] != s[1] && t[0] != t[1]) {
        vector<char> x = {'a', 'b', 'c'};
        do {
            bool ok = true;
            for (int i = 0; i < 2; i++) {
                if ((s[0] == x[i] && s[1] == x[i + 1]) || (t[0] == x[i] && t[1] == x[i + 1])) {
                    ok = false;
                }
            }
            if (ok) break;
        } while (next_permutation(x.begin(), x.end()));
        for (int i = 0; i < 3; i++) {
            ans += string(n, x[i]);
        }
    } else if (s[0] == s[1] && t[0] == t[1]) {
        for (int i = 0; i < n; i++) {
            ans += "abc";
        }
    } else {
        if (s[0] == s[1]) {
            swap(s, t);
        }
        char c = 'd' - (s[0] - 'a' + s[1] - 'a');
        string tmp = string(1, s[0]);
        tmp += c;
        tmp += s[1];
        for (int i = 0; i < n; i++) {
            ans += tmp;
        }
    }
    cout << "YES" << '\n';
    cout << ans << '\n';
    return 0;
}