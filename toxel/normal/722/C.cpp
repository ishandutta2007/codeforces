#include<bits/stdc++.h>
using namespace std;

const long long N = 100010;

typedef struct point
{
	long long parent, total;
};

point points[N];
long long n, a[N], b[N], ans[N];

long long find(long long x)
{
	if (points[x].parent == x)
		return x;
	points[x].parent = find(points[x].parent);
	points[x].total = points[points[x].parent].total;
	return points[x].parent;
}

void unite (long long u, long long v)
{
	long long x = find (u), y = find(v);
	points[x].parent = y;
	points[y].total += points[x].total;
	find(u);
}

int main()
{
	memset(ans, 0, sizeof(ans));
	scanf("%I64d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &b[i]);
		b[i]--;
	}
	for (int i = 0; i < n; i++)
	{
		points[i].total = -1;
		points[i].parent = i;
	}
	for (int i = n - 1; i; i--)
	{
		points[b[i]].total = a[b[i]];;
		if (b[i])
		{
			find(b[i] - 1);
			if (points[b[i] - 1].total >= 0)
				unite(b[i] - 1, b[i]);
		}
		if (b[i] < n - 1)
		{
			find(b[i] + 1);
			if (points[b[i] + 1].total >= 0)
				unite(b[i] + 1, b[i]);
		}
		ans[i] = max(ans[i + 1], points[b[i]].total);
	}
	for (int i = 1;i <= n - 1; i++)
		printf("%I64d\n", ans[i]);
	printf("0\n");
	return 0;
}