#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, l, r, c;

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        int l1 = INF, r1 = 0, c1 = INF;
        int l2 = INF, r2 = 0, cl = INF, cr = INF;
        rep(i, 1, n) {
            scanf("%d%d%d", &l, &r, &c);
            if (l < l1 || r > r1 || l == l1 && r == r1 && c < c1)
                l1 = l, r1 = r, c1 = c;
            if (l < l2 || l == l2 && c < cl)
                l2 = l, cl = c;
            if (r > r2 || r == r2 && c < cr)
                r2 = r, cr = c;
            int ans = cl + cr;
            if (l1 == l2 && r1 == r2)
                ans = min(ans, c1);
            printf("%d\n", ans);
        }
    }
    return 0;
}