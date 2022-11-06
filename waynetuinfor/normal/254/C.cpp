#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int cs[26][maxn], ct[26][maxn], cr[26];

int main() {
#ifndef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    int n = (int)s.size();
    ++cs[s[0] - 'A'][0]; ++ct[t[0] - 'A'][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) cs[j][i] = cs[j][i - 1], ct[j][i] = ct[j][i - 1];
        ++cs[s[i] - 'A'][i], ++ct[t[i] - 'A'][i];
    }
    queue<int> to;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < ct[i][n - 1] - cs[i][n - 1]; ++j) to.push(i);
    }
    string res = "";
    int ans = 0;
    for (int i = 0; i < 26; ++i) if (cs[i][n - 1] > ct[i][n - 1]) ans += cs[i][n - 1] - ct[i][n - 1];
    for (int i = 0; i < n; ++i) {
        if (to.size() == 0) {
            res += s[i];
            ++cr[s[i] - 'A'];
            continue;
        }
        int c = to.front();
        int re = cs[s[i] - 'A'][n - 1] - cs[s[i] - 'A'][i];
        int cand = 0;
        for (int j = 0; j < 26; ++j) if (cs[j][n - 1] > ct[j][n - 1]) cand += cs[j][n - 1] - cs[j][i];
        if (cr[s[i] - 'A'] + re >= ct[s[i] - 'A'][n - 1] && (c < s[i] - 'A' || cand < to.size() || cr[s[i] - 'A'] == ct[s[i] - 'A'][n - 1])) {
            ++cr[c]; 
            res += (char)(c + 'A');
            to.pop();
            continue;
        }
        res += s[i];
        ++cr[s[i] - 'A'];
    }
    cout << ans << endl;
    cout << res << endl;
    return 0;
}