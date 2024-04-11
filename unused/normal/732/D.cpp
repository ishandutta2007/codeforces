#include "bits/stdc++.h"
using namespace std;

int need[100005];
int exam[100005];
int last[100005];
int n, m;

bool check(int mid)
{
	memset(last, -1, 4 * m + 4);
	priority_queue<pair<int,int>> pq;

	for (int i = 0; i < mid; i++)
	{
		last[exam[i]] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		if (last[i] == -1) return false;
		pq.emplace(-last[i], i);
	}

	int studied = 0, day = 0;
	while (pq.empty() == false)
	{
		int a, b;
		tie(a, b) = pq.top();
		a = -a;
		pq.pop();

		studied += a - day;
		day = a + 1;

		if (studied < need[b]) return false;
		studied -= need[b];
	}

	return true;
}

int main()
{
	scanf("%d%d",&n,&m);

	int lo = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d",&exam[i]);
	}

	for (int i = 1; i <= m; i++)
	{
		scanf("%d",&need[i]);
		lo += need[i];
		if (lo > n - m)
		{
			printf("-1");
			return 0;
		}
	}

	int hi = n, ans = -1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid))
		{
			ans = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	printf("%d", ans);
}