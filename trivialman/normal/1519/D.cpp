#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 5005;
mt19937 rng(time(0));

int T, n, a[N], b[N];

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n) scanf("%d", b + i);
    LL ans = 0, maxdiff = 0, diff;
    rep(i, 1, n) ans += 1ll * a[i] * b[i];

    rep(mid, 1, n) {
        //mid on integer
        int num = min(mid - 1, n - mid);
        diff = 0;
        rep(i, 1, num) {
            diff += 1ll * a[mid - i] * b[mid + i] + 1ll * a[mid + i] * b[mid - i] - 1ll * a[mid - i] * b[mid - i] - 1ll * a[mid + i] * b[mid + i];
            maxdiff = max(diff, maxdiff);
        }
        //mid on .5
        if (mid != n) {
            int num = min(mid, n - mid);
            diff = 0;
            rep(i, 1, num) {
                diff += 1ll * a[mid + 1 - i] * b[mid + i] + 1ll * a[mid + i] * b[mid + 1 - i] - 1ll * a[mid + 1 - i] * b[mid + 1 - i] - 1ll * a[mid + i] * b[mid + i];
                maxdiff = max(maxdiff, diff);
            }
        }
    }
    cout << ans + maxdiff;
    return 0;
}