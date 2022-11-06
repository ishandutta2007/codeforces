#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
        char prv = s[i - 1];
        char lst = i + 1 < (int)s.size() ? s[i + 1] : 'Z';
        if (s[i] != prv) continue;
        while (s[i] == prv || s[i] == lst) {
            s[i] = s[i] == 'R' ? 'G' : s[i] == 'G' ? 'B' : 'R';
        }
        ++ans;
    }
    cout << ans << endl;
    cout << s << endl;
}