#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int ok[maxn];
int p[maxn], g[2][maxn];
pair<int, int> dp[maxn];

pair<int, int> cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second < b.second ? a : b;
    return a.first > b.first ? a : b;
}

pair<int, int> merge(const pair<int, int> &a, const pair<int, int> &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

int main() {
    int n; cin >> n;
    string s; cin >> s; s = '.' + s;
    int m; cin >> m;
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1];
        if (s[i] == '?') ++p[i];
    } 
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '?') {
            g[0][i] = g[0][i - 1] + 1;
            g[1][i] = g[1][i - 1] + 1;
            continue;
        }
        g[1 ^ (i & 1) ^ (s[i] - 'a')][i] = g[1 ^ (i & 1) ^ (s[i] - 'a')][i - 1] + 1;
        g[(i & 1) ^ (s[i] - 'a')][i] = 0;
    }     
    int ed = (m & 1) ^ 1, ch = m & 1;
    for (int i = m; i <= n; ++i) {
        if (g[ed ^ 1 ^ (i & 1)][i] - g[ed ^ 1 ^ (i & 1)][i - m] == m) ok[i] = 1;
        else ok[i] = 0;
    }
    fill(dp, dp + maxn, make_pair(0, 0));
    pair<int, int> t = make_pair(0, 0);
    dp[0] = make_pair(0, 0);
    for (int i = m; i <= n; ++i) {
         t = cmp(t, dp[i - m]);
         dp[i] = dp[i - 1];
         if (ok[i]) dp[i] = cmp(dp[i], merge(t, make_pair(1, p[i] - p[i - m])));
    }
    cout << dp[n].second << endl;
    return 0;
}