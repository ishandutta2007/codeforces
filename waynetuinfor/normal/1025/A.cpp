#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < s.size(); ++i) ++cnt[s[i] - 'a'];
    int c = 0;
    for (int i = 0; i < 26; ++i) if (cnt[i]) ++c;
    if (c == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    if (*max_element(cnt, cnt + 26) > 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    } 
}