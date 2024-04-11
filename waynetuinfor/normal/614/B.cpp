#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string t;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (s == "0") return cout << 0 << endl, 0;
        int a = 0, b = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == '1') ++a;
            else if (s[j] == '0') ++b;
            else a = -100001, b = -100001;
        }
        if (a < 0 && b < 0) { t = s; continue; }
        if (a > 1) { t = s; continue; }
        cnt += b;
    }
    if (t.length()) {
        cout << t;
        for (int i = 0; i < cnt; ++i) cout << 0; cout << endl;
    } else {
        cout << 1;
        for (int i = 0; i < cnt; ++i) cout << 0; cout << endl;
    }
    return 0;
}