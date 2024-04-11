#include <bits/stdc++.h>
using namespace std;

const int maxn = 700 + 10, mod = 1e9 + 7;
int dp[3][3][maxn][maxn], match[maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int go(int lc, int rc, int l, int r) {
    if (l > r) return 1;
    if (dp[lc][rc][l][r]) return dp[lc][rc][l][r];
    dp[lc][rc][l][r] = 0;
    int p = match[l];
    if (lc != 1) dp[lc][rc][l][r] = add(dp[lc][rc][l][r], mul(go(1, 0, l + 1, p - 1), go(0, rc, p + 1, r)));
    if (lc != 2) dp[lc][rc][l][r] = add(dp[lc][rc][l][r], mul(go(2, 0, l + 1, p - 1), go(0, rc, p + 1, r)));
    if (r == match[l]) {
        if (rc != 1) dp[lc][rc][l][r] = add(dp[lc][rc][l][r], go(0, 1, l + 1, p - 1));
        if (rc != 2) dp[lc][rc][l][r] = add(dp[lc][rc][l][r], go(0, 2, l + 1, p - 1));
    } else {
        dp[lc][rc][l][r] = add(dp[lc][rc][l][r], mul(go(0, 1, l + 1, p - 1), go(1, rc, p + 1, r)));
        dp[lc][rc][l][r] = add(dp[lc][rc][l][r], mul(go(0, 2, l + 1, p - 1), go(2, rc, p + 1, r)));
    }
    return dp[lc][rc][l][r];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int n = s.length();
    s = '.' + s;
    stack<int> stk;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') stk.push(i);
        else match[i] = stk.top(), match[stk.top()] = i, stk.pop();
    }
    cout << go(0, 0, 1, n) << endl;
    return 0;
}