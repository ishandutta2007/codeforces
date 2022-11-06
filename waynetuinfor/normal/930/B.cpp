#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
int c[26][26][maxn], cnt[26];

string shift(const string &s) {
    string t = "";
    t += s[s.size() - 1];
    for (int i = 0; i < (int)s.size() - 1; ++i) t += s[i];
    return t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    string t = s;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        // cout << "t = " << t << endl;
        for (int j = 1; j < n; ++j) ++c[t[0] - 'a'][t[j] - 'a'][j];
        ++cnt[t[0] - 'a'];
        t = shift(t);
    }
    long double ans = 0.0;
    for (char ch = 'a'; ch <= 'z'; ++ch) if (cnt[ch - 'a'] > 0) {
        if (cnt[ch - 'a'] == 1) {
            ans += 1.0 * cnt[ch - 'a'] / n;
            continue;
        }
        long double cur = 0.0;
        for (int j = 1; j < n; ++j) {
            int s = 0;
            for (int k = 0; k < 26; ++k) s += (c[ch - 'a'][k][j] == 1);
            cur = max(cur, (long double)1.0 * s / cnt[ch - 'a']);
        }
        ans += 1.0 * cur * cnt[ch - 'a'] / n;
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}