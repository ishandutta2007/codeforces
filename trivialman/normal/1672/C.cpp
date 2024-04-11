#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e6;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        int mi = n + 1, ma = 0;
        rep(i, 2, n) if (a[i] == a[i - 1])
            mi = min(mi, i),
            ma = max(ma, i);
        mi--;
        int ans = ma - mi <= 1 ? 0 : (ma - mi == 2 ? 1 : ma - mi - 2);
        cout << ans << "\n";
    }
    return 0;
}