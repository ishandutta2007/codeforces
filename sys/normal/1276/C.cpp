#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 400005;
int n, a[Maxn], b[Maxn], cnt[Maxn], ans, x, y, ct, nowx, nowy;
map <int, int> num[Maxn];
pair <int, int> P[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int m = unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b, cnt[a[i]]++;
	int maxi = sqrt(n);
	for (int i = 1; i <= maxi; i++)
	{
		int now = 0;
		for (int j = 1; j <= m; j++)
			now += min(cnt[j], i);
		if (now < i * i) continue;
		if (now / i * i > ans) ans = now / i * i, x = i, y = now / i;
	}
	int tmp = ans;
	for (int j = 1; j <= m; j++)
	{
		if (!tmp) break;
		P[++ct] = make_pair(min(min(tmp, x), cnt[j]), j);
		tmp -= P[ct].first;
	}
	sort(P + 1, P + 1 + ct);
	printf("%d\n%d %d\n", ans, x, y);
	nowx = nowy = 1;
	for (int i = 1; i <= ans; i++)
	{
		num[nowx][nowy] = P[ct].second;
		P[ct].first--;
		if (!P[ct].first) ct--;
		nowx++, nowy++;
		if (nowx == x + 1) nowx -= x, nowy -= x - 1;
		if (nowy <= 0) nowy += y;
		if (nowy > y) nowy -= y;
	}
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
			printf("%d ", b[num[i][j]]);
		printf("\n");
	}
	return 0;
}