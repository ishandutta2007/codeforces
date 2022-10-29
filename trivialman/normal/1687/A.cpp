#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
int P = 998244353;
const int INF = 1e9 + 1;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T;
LL n, k, a[N], s[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    rep(cas, 1, T) {
        cin >> n >> k;
        rep(i, 1, n) cin >> a[i];
        s[0] = 0;
        rep(i, 1, n) s[i] = s[i - 1] + a[i];
        if (k >= n) {
            cout << s[n] + n * (k + k - n - 1) / 2 << "\n";
        } else {
            LL ans = 0;
            rep(i, 0, n - k) ans = max(ans, s[i + k] - s[i] + k * (k - 1) / 2);
            cout << ans << "\n";
        }
    }
    return 0;
}