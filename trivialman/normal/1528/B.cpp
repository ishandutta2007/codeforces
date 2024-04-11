#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1e6 + 5;
mt19937 rng(time(0));

int T, n;
int dp[N], p[N], nfac[N];

int main() {
    cin >> n;
    rep(i, 1, n) p[i] = i;
    rep(i, 2, n) if (p[i] == i) {
        for (int j = i + i; j <= n; j += i)
            p[j] = i;
    }

    int sum;
    sum = dp[1] = 1, nfac[1] = 1;
    rep(i, 2, n) {
        int x = i, y = p[x], cnt = 0;
        while (p[x] == y)
            cnt++, x /= y;
        nfac[i] = nfac[x] * (cnt + 1);
        dp[i] = (sum + nfac[i]) % P;
        sum = (sum + dp[i]) % P;
    }
    cout << dp[n] << endl;
    return 0;
}