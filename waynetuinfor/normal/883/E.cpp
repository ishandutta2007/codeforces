#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int cnt[26];
bool ban[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) ban[s[i] - 'a'] = true;
    int m, c; cin >> m; c = m; 
    for (int j = 0; j < m; ++j) {
        string t; cin >> t;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '*' && t[i] != s[i]) ok = false;
            if (s[i] == '*' && t[i] != '*' && ban[t[i] - 'a']) ok = false;
        }
        if (!ok) {
            --c;
            continue;
        }
        bitset<26> v;
        for (int i = 0; i < t.length(); ++i) v[t[i] - 'a'] = true;
        for (int i = 0; i < 26; ++i) if (v[i]) ++cnt[i];
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] == c && !ban[i]) ++ans; 
    }
    cout << ans << endl;
    return 0;
}