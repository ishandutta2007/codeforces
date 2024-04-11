#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s >> s;
    int ans = 0;
    while (true) {
        // ++ans;
        int pos = -1;
        for (int i = s.size() - 1; i >= 1; --i) {
            if (s[i] == s[i - 1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) break;
        ++ans;
        string t = "";
        for (int i = 0; i < pos; ++i) t += s[i];
        for (int i = pos + 1; i < s.size(); ++i) t += s[i];
        s = t;
    }
    cout << ans << endl;
}