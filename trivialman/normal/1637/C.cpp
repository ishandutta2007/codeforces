#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, a[N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        rep(i, 1, n) scanf("%d", a + i);
        bool flag = false;
        rep(i, 2, n - 1) flag |= (a[i] > 1);
        if (n == 3 && a[2] % 2 == 1 || !flag) {
            printf("-1\n");
            continue;
        }
        LL ans = 0;
        rep(i, 2, n - 1) ans += (a[i] + 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}