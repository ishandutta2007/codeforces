#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(const string &s) {
    vector<int> f(s.size(), 0);
    // f[i] = length of the longest prefix (excluding s[0:i]) such that it coincides with the suffix of s[0:i] of the same length
    // i + 1 - f[i] is the length of the smallest recurring period of s[0:i]
    int k = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
        while (k > 0 && s[i] != s[k]) k = f[k - 1];
        if (s[i] == s[k]) ++k;
        f[i] = k;
    }
    return f;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    string s, t; cin >> s >> t;
    vector<int> f = kmp(t);
    int rec = (int)t.size() - f.back();
    vector<int> cnt(2, 0);
    vector<int> need(2, 0);
    for (int i = 0; i < (int)s.size(); ++i) ++cnt[s[i] - '0'];
    string ans = "";
    for (int i = 0; i < (int)s.size(); ++i) {
        if (cnt[t[i % rec] - '0']) {
            putchar(t[i % rec]);
            cnt[t[i % rec] - '0']--;
        } else {
            putchar(t[i % rec] ^ 1);
            cnt[(t[i % rec] - '0') ^ 1]--;
        }
    }
    return 0;
}