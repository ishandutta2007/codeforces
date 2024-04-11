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

int m[4001][4001];
inline int M(int i, int j) {
    if(i < 0 || j < 0) return 0;
    return m[i][j];
}

inline int acc(int i, int j) {
    return (M(j, j) - M(i - 1, j) - M(j, i - 1) + M(i - 1, i - 1)) >> 1;
}

int dp[4006][803];

void solve(int l, int r, int lo, int ro, int q) {
    if(r < l) return;
    int m = (l + r) / 2;
    int bm = 100000000, bi;
    for(int i = max(lo, m); i <= ro; i++)
        if(dp[i + 1][q - 1] + acc(m, i) < bm) {
            bm = dp[i + 1][q - 1] + acc(m, i);
            bi = i;
        }
    dp[m][q] = bm;
    solve(l, m - 1, lo, bi, q);
    solve(m + 1, r, bi, ro, q);
}

inline char next_c() {
    char c;
    while(isspace(c = getchar()));
    return c;
}

int main() {
    int n, k, i, j;
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            m[i][j] = next_c() - '0';
            m[i][j] += M(i - 1, j) + M(i, j - 1) - M(i - 1, j - 1);
        }
    for(i = 0; i < n; i++)
        dp[i][0] = 100000000;
    for(i = 1; i <= k; i++)
        solve(0, n - 1, 0, n - 1, i);
    printf("%d\n", dp[0][k]);
}