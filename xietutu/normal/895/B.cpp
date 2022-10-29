#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100010;
int n, m;
LL ans, X, K, v[maxn], a[maxn], b[maxn], cnt[maxn], sum[maxn];
int main() {
	//freopen("B.in","r",stdin);
	scanf("%d%lld%lld", &n, &X, &K);
	for (int i = 1; i <= n; ++i) 
		scanf("%lld", v + i);
	sort(v + 1, v + n + 1);
	for (int i = 1; i <= n; ) {
		int j = i;
		while (j <= n && v[j] == v[i]) ++j;
		++m;
		a[m] = v[i];
		cnt[m] = j - i;
		i = j;
	}
	for (int i = 1; i <= m; ++i)
		sum[i] = sum[i - 1] + cnt[i];
	
	int lb = 1, ub = 1;
	for (int i = 1; i <= m; ++i) {
		LL L = ((a[i] + X - 1) / X + K - 1) * X;
		LL R = ((a[i] + X - 1) / X + K) * X - 1;
		while (lb <= m && a[lb] < L) ++lb;
		while (ub <= m && a[ub] <= R) ++ub;
		lb = max(lb, i);
		ans += cnt[i] * (sum[ub - 1] - sum[lb - 1]); 
		//printf("%d %lld %lld %d %d\n", i, L, R, lb, ub);
	}
	cout << ans << endl;
}