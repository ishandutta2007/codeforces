#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 505;

int n, a[N], ans[N][N];

int main() {
    cin >> n;
    rep(i, 1, n) cin >> a[i];

    rep(i, 1, n) {
        int x = i, y = i;
        rep(j, 1, a[i]) {
            ans[x][y] = a[i];
            (y > 1 && !ans[x][y - 1]) ? y-- : x++;
        }
    }

    rep(i, 1, n) {
        rep(j, 1, i) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}