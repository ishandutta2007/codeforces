#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 9e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

struct dat {
    int a, b;
} a[N];
int T, n;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        int m = 0, i1 = 0, i2 = 0;
        LL ans = 0;
        rep(i, 1, n) cin >> a[i].a, m += a[i].a;
        m = min(m, n - m);
        rep(i, 1, n) cin >> a[i].b, ans += a[i].b;
        sort(a + 1, a + n + 1, [](dat x, dat y) { return x.b > y.b; });
        rep(i, 1, n) {
            if (a[i].a == 0 && i1 < m)
                i1++, ans += a[i].b;
            if (a[i].a == 1 && i2 < m)
                i2++, ans += a[i].b;
        }
        if (m * 2 == n)
            ans -= a[n].b;
        cout << ans << "\n";
    }
    return 0;
}