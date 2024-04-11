#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 31607;
const int N = 30;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, a[N][N], pr[N], pc[1 << 21][N];
int pdiag[4];

int pw(int x, int n) {
    int res = 1;
    for (; n; n >>= 1, x = x * x % P)
        if (n & 1)
            res = res * x % P;
    return res;
}

int calc(int diag1, int diag2) {
    rep(i, 1, n) {
        pr[i] = 1;
        rep(j, 1, n) {
            int mul = (diag1 && i == j || diag2 && i + j == n + 1) ? 1 : a[i][j];
            pr[i] = pr[i] * mul % P;
        }
    }

    int ans = 0;
    rrep(mask, (1 << n) - 1, 0) {
        int p = 1;
        rep(i, 0, n - 1) if (mask >> i & 1) p = p * pr[i + 1] % P;
        if (mask == (1 << n) - 1) {
            rep(j, 1, n) pc[mask][j] = 1;
        } else {
            int unoccupy;
            rep(i, 0, n - 1) if (!(mask >> i & 1)) {
                unoccupy = i + 1;
                break;
            }
            int mask1 = mask + (1 << (unoccupy - 1));
            rep(j, 1, n) {
                int mul = (diag1 && unoccupy == j || diag2 && unoccupy + j == n + 1) ? 1 : a[unoccupy][j];
                pc[mask][j] = pc[mask1][j] * mul % P;
                //assert(pc[mask][j] >= 0);
            }
            //cerr << unoccupy << endl;
            //rep(j, 1, n) cerr << pc[mask][j] << " ";
            //cerr << endl;
        }

        int p1 = 1;
        rep(j, 1, n) p1 = p1 * (P + 1 - pc[mask][j]) % P;
        p = (__builtin_popcount(mask) % 2 ? 1 : -1) * p * p1 % P;
        //cerr << mask << " " << p << endl;
        ans = (ans + p + P) % P;
    }
    if (!diag1 && !diag2)
        ans = (ans + 1) % P;
    ans = ans * pdiag[diag1 + 2 * diag2] % P;
    return (ans + P) % P;
}

int main() {
    cin >> n;
    int inv10000 = pw(10000, P - 2);
    rep(i, 1, n) rep(j, 1, n) cin >> a[i][j], a[i][j] = a[i][j] * inv10000 % P;

    pdiag[0] = pdiag[1] = pdiag[2] = 1;
    rep(i, 1, n) pdiag[1] = pdiag[1] * a[i][i] % P, pdiag[2] = pdiag[2] * a[i][n + 1 - i] % P;
    pdiag[3] = pdiag[1] * pdiag[2] % P;
    pdiag[1] *= -1, pdiag[2] *= -1;
    if (n % 2)
        pdiag[3] = pdiag[3] * pw(a[(n + 1) / 2][(n + 1) / 2], P - 2) % P;
    cerr << pdiag[0] << " " << pdiag[1] << " " << pdiag[2] << " " << pdiag[3] << endl;

    int ans1 = calc(0, 0), ans2 = calc(0, 1), ans3 = calc(1, 0), ans4 = calc(1, 1);
    int ans = (ans1 + ans2 + ans3 + ans4) % P;

    cout << ans << endl;
    cerr << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
    return 0;
}