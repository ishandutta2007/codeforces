#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, x;
int a[N];

LL calc(int x) {
    LL res = 0;
    int k = 1;
    rep(i, 1, (n + 1) / 2) {
        while (a[k] != x)
            k++;
        res += abs(k - (i * 2 - 1));
        k++;
    }
    return res;
}

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        int cnt = 0;
        rep(i, 1, n) {
            scanf("%d", &x);
            a[i] = x % 2;
            cnt += a[i];
        }
        if (abs(cnt - (n - cnt)) >= 2) {
            printf("-1\n");
            continue;
        }

        LL ans = INF;
        if (cnt >= n - cnt)
            ans = min(ans, calc(1));
        if (cnt <= n - cnt)
            ans = min(ans, calc(0));
        printf("%lld\n", ans);
    }
    return 0;
}