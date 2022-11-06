#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == 'V' && s[i + 1] == 'K') ++ans;
    }
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        s[i] = c == 'K' ? 'V' : 'K';
        int cur = 0;
        for (int j = 0; j < s.length() - 1; ++j) {
            if (s[j] == 'V' && s[j + 1] == 'K') ++cur;
        }
        ans = max(ans, cur);
        s[i] = c;
    }
    cout << ans << '\n';
    return 0;
}