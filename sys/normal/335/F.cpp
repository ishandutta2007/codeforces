#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 500005;
int n, len, maxi, maxi_len, a[Maxn];
long long sum, ans, val1[Maxn], val2[Maxn];
multiset <long long, greater <long long> > Se;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum += a[i];
	sort(a + 1, a + 1 + n);
	a[n + 1] = a[n];
	a[0] = -1;
	for (int i = n; i >= 0; i--)
	{
		if (a[i] != a[i + 1])
		{
			int tmp_len = len, delta = min(len, n - i - len - 2 * maxi);
			tmp_len -= delta;
			maxi += delta + min(maxi, tmp_len / 2);
			int lt = max(1, maxi - len + 1);
			while ((int) Se.size() >= lt)
				val1[Se.size()] = *Se.rbegin(), Se.erase(--Se.end());
			for (int j = lt; j <= maxi; j++)
				val2[j] = a[i + 1];
			for (int j = lt; j <= maxi; j++)
				val1[j] = max(val1[j], val2[j]);
			int pnt = maxi + (((n - i) & 1) && len * 2 < n - i);
			for (int j = lt; j <= maxi; j++)
				if (j < pnt && val1[j] > val2[j]) val2[pnt] -= val1[j] - val2[j], val2[j] = val1[j], pnt--;
			for (int j = lt; j <= maxi; j++)
				Se.insert(max(val2[j], 0LL));
			len = 1;
		}
		else len++;
	}
	while (!Se.empty()) ans += *Se.rbegin(), Se.erase(--Se.end());
	printf("%lld", sum - ans);
	return 0;
}