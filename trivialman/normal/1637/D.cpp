#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
int P = 998244353;
const int INF = 1e9 + 1;
const int N = 1005;
mt19937 rng(time(0));

int T, n, a[N], b[N];
bool f[10005], g[10005];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) cin >> b[i];
        LL ans = 0, sum = 0;
        rep(i, 1, n) sum += a[i] + b[i];
        rep(i, 1, n) ans += a[i] * a[i] + b[i] * b[i];
        ans = ans * (n - 2);

        memset(f, 0, sizeof f);
        f[0] = true;
        rep(i, 1, n) {
            rep(j, 0, sum / 2) g[j] = false;
            rrep(j, sum / 2, 1) if (j >= a[i] && f[j - a[i]] || j >= b[i] && f[j - b[i]]) g[j] = true;
            rep(j, 0, sum / 2) f[j] = g[j];
        }
        int x = 0;
        rep(j, 1, sum / 2) if (f[j]) x = j;
        ans += 1ll * x * x + 1ll * (sum - x) * (sum - x);
        cout << ans << endl;
    }
    return 0;
}