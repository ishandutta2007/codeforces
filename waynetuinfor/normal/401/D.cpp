#include <bits/stdc++.h>
using namespace std;

const int maxn = 18, maxm = 100 + 10;
long long dp[1 << maxn][maxm], n, f[maxn];
int m, t[maxn], c, cnt[10];
bool v[1 << maxn][maxm];
vector<int> dig;

long long go(int s, int r) {
    if (s == 0) {
        if (r == 0) return 1;
        return 0;
    }
    if (v[s][r]) return dp[s][r];
    dp[s][r] = 0;
    v[s][r] = true;
    int p = __builtin_popcount(s);
    if (p == 1) {
        int k = 31 - __builtin_clz(s);
        if (r == dig[k] % m) return dp[s][r] = 1;
        return dp[s][r] = 0;
    }
    int used = 0;
    for (int i = 0; i < c; ++i) if ((1 << i) & s) {
        if ((1 << dig[i]) & used) continue;
        used |= (1 << dig[i]);
        if (dig[i] == 0 && p == c) continue;
        int g = (r - dig[i] * t[p - 1] % m + m) % m;
        dp[s][r] += go(s ^ (1 << i), g);
    }
    return dp[s][r];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (; n; n /= 10) dig.push_back(n % 10), ++cnt[n % 10];
    sort(dig.begin(), dig.end());
    t[0] = 1;
    for (int i = 1; i < maxn; ++i) t[i] = t[i - 1] * 10 % m;
    f[0] = 1;
    for (int i = 1; i < maxn; ++i) f[i] = f[i - 1] * i;
    c = (int)dig.size();
    long long ans = go((1 << c) - 1, 0);
    // for (int i = 0; i < 10; ++i) ans /= f[cnt[i]];
    cout << ans << endl;
    return 0;
}