#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxx = 30 + 5, p = 131, mod = 1073807359;
int dp[maxx][maxn], n, m;
long long hashs[maxn], hasht[maxn], pp[maxn];
string s, t;

void init();
bool check(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s >> m >> t; s = "." + s; t = "," + t;
    int x; cin >> x;
    init();
    dp[0][0] = 0;
    for (int i = 0; i <= x; ++i) for (int j = 0; j <= n; ++j) {
        if (j + 1 <= n) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
        int d = 1, lcp = 0; while (d <= n + 1) d <<= 1;
        while (d >>= 1) if (lcp + d <= n + 1) if (check(j + 1, dp[i][j] + 1, lcp + d)) lcp += d;
        if (i + 1 <= x && j + lcp <= n) dp[i + 1][j + lcp] = max(dp[i + 1][j + lcp], dp[i][j] + lcp); 
    }
    /* for (int i = 0; i <= x; ++i) {
        for (int j = 0; j < n; ++j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << ' '; cout << endl;
    } */
    cout << (dp[x][n] == m ? "YES" : "NO") << endl;
    return 0;
}

void init() {
    pp[0] = 1LL;
    for (int i = 1; i < maxn; ++i) pp[i] = pp[i - 1] * p % mod;
    hashs[0] = s[0];
    for (int i = 1; i <= n; ++i) hashs[i] = (p * hashs[i - 1] % mod + s[i]) % mod;
    hasht[0] = t[0];
    for (int i = 1; i <= m; ++i) hasht[i] = (p * hasht[i - 1] % mod + t[i]) % mod;
}

bool check(int sind, int tind, int lcp) {
    if (sind > n || tind > m) return false;
    if (sind + lcp > n + 1 || tind + lcp > m + 1) return false;
    long long hs = (((hashs[sind + lcp - 1] - (pp[lcp] * hashs[sind - 1]) % mod) % mod) + mod) % mod;
    long long ht = (((hasht[tind + lcp - 1] - (pp[lcp] * hasht[tind - 1]) % mod) % mod) + mod) % mod;
    return hs == ht;
}