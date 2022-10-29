#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 105;

int T, n, l, r;

inline int cntbit(int n, int k) { return (n + 1) / (k * 2) * k + max(0, (n + 1) % (2 * k) - k); }

int main() {
    cin >> T;
    while (T--) {
        scanf("%d%d", &l, &r);
        int ans = 0;
        rep(i, 0, 18) ans = max(ans, cntbit(r, 1 << i) - cntbit(l - 1, 1 << i));
        printf("%d\n", r - l + 1 - ans);
    }
    return 0;
}