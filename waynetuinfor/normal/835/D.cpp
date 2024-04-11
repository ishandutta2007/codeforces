#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
const long long p = 277, mod = 1073807359;
string s;
long long dp[maxn][maxn];
long long ans[20];
long long h[2][maxn], pp[maxn];

inline bool check(int l, int r) {
    long long h1, h2;
    if (l == 0) h1 = h[0][r];
    else h1 = (((h[0][r] - pp[r - l + 1] * h[0][l - 1] % mod) % mod) + mod) % mod;
    if (r == s.length() - 1) h2 = h[1][l];
    else h2 = (((h[1][l] - pp[r - l + 1] * h[1][r + 1] % mod) % mod) + mod) % mod;
    return h1 == h2;
}

inline bool osas(int l1, int r1, int l2, int r2) {
    if (r1 - l1 + 1 <= 0 || r2 - l2 + 1 <= 0) return true;
    long long h1, h2;
    if (l1 == 0) h1 = h[0][r1];
    else h1 = (((h[0][r1] - pp[r1 - l1 + 1] * h[0][l1 - 1] % mod) % mod) + mod) % mod;
    if (l2 == 0) h2 = h[0][r2];
    else h2 = (((h[0][r2] - pp[r2 - l2 + 1] * h[0][l2 - 1] % mod) % mod) + mod) % mod;
    return h1 == h2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    pp[0] = 1LL; 
    for (int i = 1; i < maxn; ++i) pp[i] = (pp[i - 1] * p) % mod;
    h[0][0] = s[0]; 
    for (int i = 1; i < s.length(); ++i) h[0][i] = (h[0][i - 1] * p % mod + s[i]) % mod;
    h[1][s.length() - 1] = s[s.length() - 1];
    for (int i = s.length() - 2; i >= 0; --i) h[1][i] = (h[1][i + 1] * p % mod + s[i]) % mod;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            if (check(i, j)) dp[i][j] = max(dp[i][j], 1LL);
        }
    }
    for (int k = 2; k <= s.length(); ++k) {
        for (int i = 0; i < s.length() - k + 1; ++i) {
            int j = i + k - 1;
            int len = k;
            if (i + len / 2 - 1 < i || j - len / 2 + 1 > j) continue;
            // if (!osas(i, i + len / 2 - 1, j - len / 2 + 1, j)) continue;
            if (!check(i, j)) continue;
            if (len & 1) {
                dp[i][j] = max(dp[i][j], dp[i][i + len / 2 - 1] + 1);
            } else {
                if (s[i + len / 2 - 1] == s[j - len / 2 + 1]) dp[i][j] = max(dp[i][j], dp[i][i + len / 2 - 1] + 1);
            }
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            // assert(dp[i][j] <= log2(s.length()) + 1);
            for (int k = 0; k <= dp[i][j]; ++k) {
                if ((1 << (k - 1)) > s.length()) break;
                ++ans[k];
            }
        } 
    }
    bool bang = false;
    for (int i = 1; i <= s.length(); ++i) {
        if (bang) cout << 0 << ' ';
        else if (!bang && (1 << (i - 1)) > s.length()) {
            cout << 0 << ' ';
            bang = true;
        }
        else cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}