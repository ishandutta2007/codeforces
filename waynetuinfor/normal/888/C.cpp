#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
string s;
int cnt[26][maxn];

bool check(int len) {
    for (int i = 0; i < 26; ++i) {
        int c = 0, t = 0;
        for (int j = 1; j < s.length(); ++j) {
            int l = j, r = j + len - 1;
            if (r >= s.length()) break;
            ++t;
            c += (cnt[i][r] - cnt[i][l - 1]) > 0;
        }
        if (c == t) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s; s = '.' + s;
    for (int i = 1; i < s.length(); ++i) {
        for (int j = 0; j < 26; ++j) cnt[j][i] = cnt[j][i - 1];
        ++cnt[s[i] - 'a'][i];
    }
    int d = 1, ans = s.length(); while (d <= s.length()) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}