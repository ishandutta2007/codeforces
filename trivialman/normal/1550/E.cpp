#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
//const LL P = 998244353;
const int N = 2e5 + 5;

int T, n, k;
int nxt[18][N], succ_num[N], dp[(1 << 17) + 5];
char s[N];

bool check(int x) {
    rep(i, 0, k - 1) {
        nxt[i][n + 1] = nxt[i][n + 2] = n + 1;
        succ_num[n + 1] = 0;
        rrep(j, n, 1) {
            succ_num[j] = (s[j] == i + 'a' || s[j] == '?') ? succ_num[j + 1] + 1 : 0;
            nxt[i][j] = succ_num[j] >= x ? j + x - 1 : nxt[i][j + 1];
        }
    }

    dp[0] = 0;
    rep(mask, 1, (1 << k) - 1) {
        dp[mask] = n + 1;
        rep(i, 0, k - 1) if (mask >> i & 1) {
            int num = dp[mask - (1 << i)];
            dp[mask] = min(dp[mask], nxt[i][num + 1]);
        }
    }
    return dp[(1 << k) - 1] <= n;
}

int main() {
    cin >> n >> k;
    cin >> (s + 1);

    int l = 0, r = n / k, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << endl;
}