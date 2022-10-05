#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 500005;
int n, top, a[Maxn], sta[Maxn];
long long tot, ans, sum[Maxn];
double slope(int x, int y)
{
	return (sum[x] - sum[y]) / (double)(x - y);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), tot += i * (long long) a[i], sum[i] = sum[i - 1] + a[i];
	sta[++top] = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = top;
		while (l + 1 <= r)
		{
			int mid = (l + r) >> 1;
			if (slope(sta[mid], sta[mid + 1]) <= a[i]) l = mid + 1;
			else r = mid;
		}
		ans = max(ans, sum[i] - sum[sta[l]] + a[i] * (long long) (sta[l] - i));
		while (top > 1 && slope(sta[top], i) <= slope(sta[top - 1], sta[top])) top--;
		sta[++top] = i;
	}
	sta[top = 1] = n + 1;
	for (int i = n; i >= 1; i--)
		sum[i] = sum[i + 1] + a[i];
	for (int i = n; i >= 1; i--)
	{
		int l = 1, r = top;
		while (l + 1 <= r)
		{
			int mid = (l + r) >> 1;
			if (slope(sta[mid], sta[mid + 1]) <= -a[i]) l = mid + 1;
			else r = mid;
		}
		ans = max(ans, sum[sta[l]] - sum[i] + a[i] * (long long) (sta[l] - i));
		while (top > 1 && slope(sta[top], i) <= slope(sta[top - 1], sta[top])) top--;
		sta[++top] = i;
	}
	printf("%lld", tot + ans);
	return 0;
}