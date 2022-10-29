#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 2e18;
const int N = 1e6 + 5;
mt19937 rng(time(0));

int T, n, nx, ny;
int a[N];

bool check(LL k) {
    LL q = sqrt(k + a[1]), i = 0;
    while (q * q > k + a[1])
        q--;
    while ((q + 1) * (q + 1) <= k + a[1])
        q++;
    while (1) {
        i = upper_bound(a + 1, a + n + 1, q * q + q - k) - a;
        if (i > n)
            return true;
        if (a[i] < (q + 1) * (q + 1) - k)
            return false;
        q++;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    LL ans = check(0) ? 0 : INF;
    rep(i, 1, n) for (LL q = sqrt(a[i] - 1) + 1, k; q <= (i == 1 ? a[n] : a[i] - a[i - 1]); q++)
        k = q * q - a[i],
        ans = min(ans, check(k) ? k : INF);
    cout << ans;
    return 0;
}