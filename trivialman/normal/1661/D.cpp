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
const int N = 3e5 + 5;
mt19937 rng(time(0));

int T, n, k;
LL a[N], tr1[N], tr2[N];

void add(LL x, LL val) {
    LL val1 = val * x;
    for (; x <= n; x += x & -x)
        tr1[x] += val, tr2[x] += val1;
}
pair<LL, LL> get(LL x) {
    LL res1 = 0, res2 = 0;
    for (; x; x -= x & -x)
        res1 += tr1[x], res2 += tr2[x];
    return {res1, res2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    LL ans = 0;
    rrep(i, n, k) {
        auto [s0, s1] = get(min(n, i + k));
        LL sub = s0 * (i + k) - s1;
        a[i] -= sub;
        if (a[i] > 0) {
            LL num = (a[i] + k - 1) / k;
            a[i] -= num * k, ans += num, add(i, num);
        }
    }
    LL ans2 = 0;
    rep(i, 1, k - 1) {
        auto [s0, s1] = get(min(n, i + k));
        LL sub = s0 * (i + k) - s1;
        a[i] -= sub;
        ans2 = max(ans2, (a[i] + i - 1) / i);
    }
    cout << ans + ans2;
    return 0;
}