#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, mod = 1e9 + 7;
int dp[maxn][maxn], comb[maxn][maxn];
string n;

inline int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

void init() {
    comb[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            comb[i][j] = comb[i - 1][j];
            if (j) comb[i][j] = add(comb[i][j], comb[i - 1][j - 1]);
        }
    }
}

int cal(int c) {
    if (c == 1) return 0;
    int to = 0;
    while (c) to += (c & 1), c >>= 1;
    return cal(to) + 1;
}

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int dfs(int now, int c) {
    if (c == 0) return 1;
    if (now == n.size()) return 0;
    if (~dp[now][c]) return dp[now][c];
    int left = n.size() - now - 1;
    if (n[now] == '1') return dp[now][c] = add(dfs(now + 1, c - 1), comb[left][c]);
    return dp[now][c] = dfs(now + 1, c);
}

int main() {
    init();
    int k; cin >> n >> k;
    if (k == 0) return cout << "1" << endl, 0;
    int ans = 0;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = -1;
    // for (int i = 1; i <= 10; ++i) cout << dp[i] << ' '; cout << endl;
    for (int i = 1; i < maxn; ++i) if (cal(i) == k - 1) ans = add(ans, dfs(0, i));
    if (k == 1) --ans;
    if (ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}