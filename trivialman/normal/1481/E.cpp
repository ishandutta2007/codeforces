#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 5e5 + 5;
mt19937 rng(time(0));

struct dat {
    int l, r, cnt;
} info[N];
int remain[N];
int T, n;
int a[N], dp[N];

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n) info[i] = {n + 1, 0, 0};
    rep(i, 1, n) {
        int x = a[i];
        info[x].l = min(info[x].l, i);
        info[x].r = max(info[x].r, i);
        info[x].cnt++;
    }

    memset(dp, 0, sizeof dp); //dp[i]: max total weight of segments till i
    rep(i, 1, n) {
        dp[i] = max(dp[i], dp[i - 1]);
        int x = a[i];
        if (i == info[x].l) {
            int r = info[x].r;
            dp[r] = max(dp[r], dp[i - 1] + info[x].cnt);
        }
    }

    //special case: move part of a color to the right, and keep the (rightmost) part, moving other colors inside them.
    int ans = dp[n];
    rep(i, 1, n) remain[i] = info[i].cnt;
    rep(i, 1, n) {
        int x = a[i];
        ans = max(ans, dp[i - 1] + remain[x]);
        remain[x]--;
    }
    cout << n - ans << endl;
    return 0;
}