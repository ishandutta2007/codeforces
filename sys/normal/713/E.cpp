#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, maxi, pos, a[Maxn], b[Maxn], f[Maxn], dis[Maxn];
bool check(int d)
{
	f[1] = d;
	for (int i = 2; i <= n; i++)
		dis[i] = a[i] - a[i - 1] - 1;
	dis[1] = a[1] + m - a[n] - 1;
	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] >= dis[i] ? d : 0;
		if (i > 2) f[i] = max(f[i], f[i - 2] + d >= dis[i] + dis[i - 1] + 1 ? d - dis[i] - 1 : 0);
		if (!f[i] && f[i - 1] + d < dis[i]) goto A;
	}
	if (f[n] < dis[1]) goto A;
	return true;
	A:f[1] = 0;
	for (int i = 2; i <= n; i++)
		dis[i] = a[i] - a[i - 1] - 1;
	dis[1] = a[1] + m - a[n] - 1 - d;
	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] >= dis[i] ? d : 0;
		if (i > 2) f[i] = max(f[i], f[i - 2] + d >= dis[i] + dis[i - 1] + 1 ? d - dis[i] - 1 : 0);
		if (!f[i] && f[i - 1] + d < dis[i]) goto B;
	}
	if (f[n] < dis[1]) goto B;
	return true;
	B:
	if (2 * d >= a[2] + m - a[n] - 1)
	{
		for (int i = 2; i <= n; i++)
			dis[i] = a[i] - a[i - 1] - 1;
		dis[1] = a[2] + m - a[n] - 1 - d;
		f[1] = -0x3f3f3f3f, f[2] = d - dis[2] - 1;
		for (int i = 3; i <= n; i++)
		{
			f[i] = f[i - 1] >= dis[i] ? d : 0;
			if (i > 2) f[i] = max(f[i], f[i - 2] + d >= dis[i] + dis[i - 1] + 1 ? d - dis[i] - 1 : 0);
			if (!f[i] && f[i - 1] + d < dis[i]) goto C;
		}
		if (f[n] < dis[1]) goto C;
		return true;
	}
	C:return false;
}
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 2; i <= n; i++)
		if (b[i] - b[i - 1] > maxi)
		{
			maxi = b[i] - b[i - 1];
			pos = i;
		}
	if (b[1] + m - b[n] > maxi)
		pos = 1;
	for (int i = pos; i <= n; i++)
		a[i - pos + 1] = b[i];
	for (int i = 1; i < pos; i++)
		a[i + n - pos + 1] = b[i] + m;
	int lt = 0, rt = m;
	while (lt + 1 <= rt)
	{
		int mid = (lt + rt) >> 1;
		if (check(mid)) rt = mid;
		else lt = mid + 1;
	}
	printf("%d", lt);
	return 0;
}