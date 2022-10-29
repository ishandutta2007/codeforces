#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5 + 5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, s[N];
LL x[N], y[N], d[N], sumd[N];

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%lld%lld%d", x + i, y + i, s + i);

    x[n + 1] = y[n + 1] = x[n] + 1;
    rep(i, 1, n) {
        int j = lower_bound(x + 1, x + n + 1, y[i]) - x, dist = 0;
        d[i] = ((x[j] - y[i]) + (sumd[i - 1] - sumd[j - 1]) + (x[i + 1] - x[i]) + P) % P;
        sumd[i] = (sumd[i - 1] + d[i]) % P;
        //cerr << i << " " << j << " " << d[i] << endl;
    }

    LL ans = x[1];
    rep(i, 1, n) ans = (ans + (!s[i] ? x[i + 1] - x[i] : d[i])) % P;
    cout << ans << endl;
    return 0;
}