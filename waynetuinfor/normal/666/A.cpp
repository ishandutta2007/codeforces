#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
bool v[3][maxn], dp[3][maxn];
int t[3][maxn];
string s;

bool go(int k, int n) {
    if (k == 1 || k == 2) {
        if (n < k) return false;
    }
    if (n < 0) return false;
    if (k == 0) return n >= 4;
    if (v[k][n]) return dp[k][n];
    v[k][n] = true; dp[k][n] = false;
    string now = s.substr(n - k, k + 1);
    if (go(0, n - k - 1)) dp[k][n] = true;
    if (n - k - 1 > 0) {
        if (now != s.substr(n - k - 1 - 1, 2)) if (go(1, n - k - 1)) dp[k][n] = true;
    }
    if (n - k - 1 > 1) {
        if (now != s.substr(n - k - 1 - 2, 3)) if (go(2, n - k - 1)) dp[k][n] = true;
    }
    return dp[k][n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    int n = s.length();
    set<string> ans;
    go(0, n - 1); go(1, n - 1); go(2, n - 1);
    for (int i = 1; i < 3; ++i) {
        for (int j = 0; j < s.length(); ++j) {
            if (dp[i][j]) ans.insert(s.substr(j - i, i + 1));
        }
    }
    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); ++it) cout << *it << endl;
    return 0;
}