#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 105;

struct dat {
    int num, i, j;
} b[N * N];
int T, n, m, a[N][N], assign[N][N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d%d", &n, &m);
        rep(i, 1, n) rep(j, 1, m) assign[i][j] = 0;

        rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]), b[(i - 1) * m + j] = {a[i][j], i, j};
        sort(b + 1, b + n * m + 1, [](dat x, dat y) { return x.num < y.num; });
        rep(i, 1, m) assign[b[i].i][b[i].j] = i;

        rep(k, 1, m) {
            rep(i, 1, n) {
                bool flag = false;
                rep(j, 1, m) if (assign[i][j] == k) flag = true;
                if (!flag)
                    rep(j, 1, m) if (!assign[i][j]) {
                        assign[i][j] = k;
                        break;
                    }
            }
        }

        rep(i, 1, n) {
            rep(k, 1, m) {
                rep(j, 1, m) if (assign[i][j] == k) {
                    printf("%d ", a[i][j]);
                    break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}