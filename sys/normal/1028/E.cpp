#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n;
long long a[Maxn], b[Maxn], mini[Maxn];
queue <int> Qu;
int main()
{
	scanf("%d", &n);
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &b[i]);
		if (b[i]) flag = false;
	}
	if (flag)
	{
		puts("YES");
		for (int i = 1; i <= n; i++)
			printf("1 ");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		mini[i] = b[i == 1 ? n : i - 1] + 1;
		if (b[i] >= mini[i]) a[i] = b[i];
	}
	for (int i = 1; i <= n; i++)
		if (b[i] < mini[i] && b[i % n + 1] >= mini[i % n + 1]) Qu.push(i);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		a[u] = b[u] + (mini[u] - b[u] + a[u % n + 1] - 1) / a[u % n + 1] * a[u % n + 1];
		int to = u == 1 ? n : u - 1;
		if (b[to] < mini[to]) Qu.push(to);
	}
	for (int i = 1; i <= n; i++)
		if (!a[i] || a[i] % a[i % n + 1] != b[i])
			return puts("NO"), 0;
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%lld ", a[i]);
	return 0;
}