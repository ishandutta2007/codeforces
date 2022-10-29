#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1e6 + 5;
mt19937 rng(time(0));

LL n, r1, r2, r3, d;
LL a[N], t1[N], t2[N], dp[N][2];

int main() {
    cin >> n >> r1 >> r2 >> r3 >> d;
    r1 = min(r1, r3);
    rep(i, 1, n) {
        scanf("%lld", a + i);
        t1[i] = min(r2 + min(r1, r2), (a[i] + 2) * r1);
        t2[i] = a[i] * r1 + r3;
    }
    rep(i, 0, 1) dp[0][i] = (n - 1) * d;
    rep(i, 1, n) rep(j, 0, 1) dp[i][j] = INF;
    rep(i, 1, n) {
        //i==n-1 is a special case
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + min(t2[i], t1[i] + (i == n - 1 ? d : d * 2));
        if (i >= 2) 
            dp[i][1] = min(dp[i - 2][0], dp[i - 2][1]) + t1[i - 1] + t1[i] + d * 2;
        //cerr << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
    return 0;
}