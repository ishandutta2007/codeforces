#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 5e15 + 5;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T;
LL n, k;
LL a[N], cnt[N], s[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    rep(i, 1, n) {
        cin >> a[i];
        cnt[i] = cnt[i - 1] + (a[i] == 0);
        s[i] = s[i - 1] + a[i];
    }
    LL tot = cnt[n], sum = s[n];
    if (tot * k < abs(sum))
        return cout << -1, 0;
    LL ans = 0;
    rep(l, 1, n) rep(r, l, n) {
        LL num0 = cnt[r] - cnt[l - 1];
        LL mi = max(-num0 * k, -(tot - num0) * k - sum);
        LL ma = min(num0 * k, (tot - num0) * k - sum);
        ans = max(ans, max(abs(s[r] - s[l - 1] + mi), abs(s[r] - s[l - 1] + ma)) + 1);
    }
    cout << ans;
    return 0;
}