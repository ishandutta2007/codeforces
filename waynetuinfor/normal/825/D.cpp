#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int cnt[2][26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    for (int i = 0; i < t.length(); ++i) cnt[0][t[i] - 'a']++;
    int q = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '?') ++q;
        else ++cnt[1][s[i] - 'a'];
    }
    int ind = 1, ans = 0;
    while (true) {
        int qq = q;
        for (int i = 0; i < 26; ++i) if (cnt[0][i]) {
            int t = cnt[0][i] * ind;
            qq -= max(0, t - cnt[1][i]);
        }
        if (qq < 0) { ans = ind - 1; break; }
        ++ind;
    }
    ind = 0;
    for (int i = 0; i < 26; ++i) cnt[0][i] *= ans, cnt[0][i] = max(0, cnt[0][i] - cnt[1][i]);
    for (int i = 0; i < s.length(); ++i) {
        while (ind < 26 && cnt[0][ind] == 0) ++ind;
        if (s[i] == '?' && ind < 26) s[i] = (char)(ind + 'a'), --cnt[0][ind];
    }
    for (int i = 0; i < s.length(); ++i) if (s[i] == '?') s[i] = 'a';
    cout << s << endl;
    return 0;
}