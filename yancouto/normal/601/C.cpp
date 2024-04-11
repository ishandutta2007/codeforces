#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, m, x[109];
//double memo[103][100003];
//double solve(int i, int left) {
//      if(i == n) return 1;
//      double &r = memo[i][left];
//      if(seen[i][left]) return r;
//      seen[i][left] = 1;
//      r = 0;
//      for(int v = 1; v < left && v <= m; v++)
//              if(v != x[i])
//                      r += solve(i + 1, left - v) / (m - 1.);
//      return r;
//}

double mm[2][100003];
double ze = 0;
double& dp(int i, int left) {
        if(left < 0) return ze;
        return mm[i&1][left];
}
int main() {
        int i;
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
                scanf("%d", &x[i]);
        if(m == 1) { printf("1.000000000\n"); return 0; }
        int all = accumulate(x, x + n, 0);
        int left;
        for(left = 1; left <= all; left++)
                dp(n, left) = 1;
        for(i = n - 1; i >= 0; i--)
                for(left = 1; left <= all; left++) {
                        dp(i, left) = dp(i + 1, left - 1) - dp(i + 1, max(left - m, 1) - 1);
                        if(left - x[i] >= max(left - m, 1))
                                dp(i, left) -= dp(i + 1, left - x[i]) - dp(i + 1, left - x[i] - 1);
                        dp(i, left) /= (m - 1.);
                        dp(i, left) += dp(i, left - 1);
                }
        printf("%.15f\n", 1. + dp(0, all) * (m - 1.));
}