#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 100;
int dp[3][maxn];
pair<int, int> t[3][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    for (int i = 0; i < 3; ++i) fill(dp[i], dp[i] + maxn, maxn + 1), fill(t[i], t[i] + maxn, make_pair(-1, -1));
    int n = s.length();
    dp[0][0] = 0; 
    bool zero = false;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') zero = true;
        dp[0][i + 1] = dp[0][i] + 1; t[0][i + 1] = t[0][i];
        dp[1][i + 1] = dp[1][i] + 1; t[1][i + 1] = t[1][i];
        dp[2][i + 1] = dp[2][i] + 1; t[2][i + 1] = t[2][i];
        if (dp[(0 -(s[i] - '0') + 9) % 3][i] < dp[0][i + 1]) if (s[i] != '0' || t[(0 - (s[i] - '0') + 9) % 3][i].first != -1){
            dp[0][i + 1] = dp[(0 - (s[i] - '0') + 9) % 3][i];
            t[0][i + 1] = make_pair(i, (0 - (s[i] - '0') + 9) % 3); 
        }
        if (dp[(1 -(s[i] - '0') + 9) % 3][i] < dp[1][i + 1]) if (s[i] != '0' || t[(1 - (s[i] - '0') + 9) % 3][i].first != -1){
            dp[1][i + 1] = dp[(1 - (s[i] - '0') + 9) % 3][i];
            t[1][i + 1] = make_pair(i, (1 - (s[i] - '0') + 9) % 3); 
        }
        if (dp[(2 -(s[i] - '0') + 9) % 3][i] < dp[2][i + 1]) if (s[i] != '0' || t[(2 - (s[i] - '0') + 9) % 3][i].first != -1){
            dp[2][i + 1] = dp[(2 - (s[i] - '0') + 9) % 3][i];
            t[2][i + 1] = make_pair(i, (2 - (s[i] - '0') + 9) % 3); 
        }
    }
    string ans = "";
    int a = 0, b = n;
    while (b != -1) {
        if (t[a][b].first != -1) ans += s[t[a][b].first];
        auto p = t[a][b];
        a = p.second, b = p.first;
    }
    if (ans.length() == 0 && !zero) return cout << "-1\n", 0;
    if (ans.length() == 0 && zero) return cout << "0\n", 0;
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}