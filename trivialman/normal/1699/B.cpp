#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 505;
mt19937 rng(time(0));

int T, n, m, a[N][N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        a[1][1] = a[2][2] = 1, a[1][2] = a[2][1] = 0;
        for (int i = 1; i <= n; i += 2)
            for (int j = 1; j <= m; j += 2)
                if (j > 1) {
                    rep(x, 0, 1) rep(y, 0, 1) a[i + x][j + y] = 1 - a[i + x][j + y - 2];
                } else if (i > 1) {
                    rep(x, 0, 1) rep(y, 0, 1) a[i + x][j + y] = 1 - a[i + x - 2][j + y];
                }
        rep(i, 1, n) rep(j, 1, m) cout << a[i][j] << (j == m ? '\n' : ' ');
    }
    return 0;
}