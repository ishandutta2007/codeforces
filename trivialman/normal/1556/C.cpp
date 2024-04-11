#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
//typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1005;
mt19937 rng(time(0));

int T, n;
LL c[N], s[N], rmin[N][N], lmin[N][N];

int main() {
    cin >> n;
    s[0] = 0;
    rep(i, 1, n) cin >> c[i], s[i] = s[i - 1] + c[i] * (i % 2 ? 1 : -1);
    n = n / 2 * 2;

    for (int l = 1; l <= n; l += 2) {
        rmin[l][l + 1] = 0;
        for (int r = l + 3; r <= n; r += 2) {
            rmin[l][r] = max(rmin[l][r - 2] - c[r - 2], 0ll) + c[r - 1];
        }
    }
    for (int r = n; r >= 1; r -= 2) {
        lmin[r - 1][r] = 0;
        for (int l = r - 3; l >= 1; l -= 2) {
            lmin[l][r] = max(lmin[l + 2][r] - c[l + 2], 0ll) + c[l + 1];
        }
    }

    LL ans = 0;
    for (int l = 1; l <= n; l += 2)
        for (int r = l + 1; r <= n; r += 2) {
            LL diff = s[r - 1] - s[l];
            LL mi = max(1ll, max(lmin[l][r], rmin[l][r] - diff));
            LL ma = min(c[l], c[r] - diff);
            ans += max(ma - mi + 1, 0ll);
        }
    cout << ans << endl;
    return 0;
}