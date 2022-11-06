#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;using namespace std;
const int maxn = 21;long long a[maxn][maxn];int n, m;
template <typename T, typename U>
using data = unordered_map<T, U>;
data<long long, int> dp1[maxn][maxn], dp2[maxn][maxn];inline void merge(data<long long, int> &a, const data<long long, int> &b, long long c) {for (auto it : b) a[it.first ^ c] += it.second;}int main() {long long k;scanf("%d %d %lld", &n, &m, &k);for (register short i = 1; i <= n; ++i) {for (register short j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);}short x = (n + 1) / 2, y = (m + 1) / 2;dp1[1][1][a[1][1]] = 1;for (register short i = 1; i <= n; ++i) {for (register short j = 1; j <= m; ++j) if (i + j <= x + y) {if (i - 1 >= 1) merge(dp1[i][j], dp1[i - 1][j], a[i][j]);if (j - 1 >= 1) merge(dp1[i][j], dp1[i][j - 1], a[i][j]);}}dp2[n][m][a[n][m]] = 1;for (register short i = n; i >= 1; --i) {for (register short j = m; j >= 1; --j) if (i + j >= x + y) {if (i + 1 <= n) merge(dp2[i][j], dp2[i + 1][j], a[i][j]);if (j + 1 <= m) merge(dp2[i][j], dp2[i][j + 1], a[i][j]);}}long long ans = 0;for (register short i = -20; i <= 20; ++i) {short tx = x + i, ty = y - i;if (tx < 1 || tx > n || ty < 1 || ty > m) continue;long long tk = (k ^ a[tx][ty]);for (auto it : dp1[tx][ty]) ans += it.second * 1ll * dp2[tx][ty][it.first ^ tk];}printf("%lld\n", ans);return 0;}