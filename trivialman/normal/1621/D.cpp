#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 2e11;
const int N = 505;
mt19937 rng(time(0));
 
int T, n, x;
LL a[N][N];
 
int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        rep(i, 1, n * 2) rep(j, 1, n * 2) scanf("%lld", &a[i][j]);
        LL ans = INF;
        vector<int> x = {0, 1, n + 1, 1, n * 2, n, n + 1, n, n * 2};
        vector<int> y = {0, n + 1, 1, n * 2, 1, n + 1, n, n * 2, n};
        rep(i, 1, 8) ans = min(ans, a[x[i]][y[i]]);
        rep(i, n + 1, n * 2) rep(j, n + 1, n * 2) ans += a[i][j];
        printf("%lld\n", ans);
    }
    return 0;
}