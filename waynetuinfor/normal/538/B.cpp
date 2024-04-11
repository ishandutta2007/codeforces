#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) cnt = max(cnt, s[i] - '0');
    cout << cnt << '\n';
    for (int i = 0; i < cnt; ++i) {
        string t = "";
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == '0') t += '0';
            else t += '1', s[j]--;
        }
        bool jizz = true;
        for (int j = 0; j < t.length(); ++j) {
            if (jizz && t[j] == '0') continue;
            else if (t[j] == '1') jizz = false;
            cout << t[j];
        }
        cout << ' ';
    }
    return 0;
}