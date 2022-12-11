#include <bits/stdc++.h>
using namespace std;

int dat[200005];
int ans[200005];
set<int> visit;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int odd = 0, even = 0;
	int no = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		if (visit.count(dat[i]))
		{
			no++;
			ans[i] = -1;
		}
		else if (dat[i] & 1)
		{
			if (odd == n / 2)
			{
				no++;
				ans[i] = -1;
			}
			else
			{
				visit.insert(dat[i]);
				ans[i] = dat[i];
				odd++;
			}
		}
		else
		{
			if (even == n / 2)
			{
				no++;
				ans[i] = -1;
			}
			else
			{
				visit.insert(dat[i]);
				ans[i] = dat[i];
				even++;
			}
		}
	}

	if (odd < n / 2)
	{
		int z = 1;
		for (int i = 0; i < n; i++)
		{
			if (ans[i] != -1) continue;
			while (visit.count(z) && z <= m) z += 2;
			if (z > m)
			{
				printf("-1");
				return 0;
			}
			ans[i] = z;
			visit.insert(z);
			if (++odd == n / 2) break;
		}
	}
	if (even < n / 2)
	{
		int z = 2;
		for (int i = 0; i < n; i++)
		{
			if (ans[i] != -1) continue;
			while (visit.count(z) && z <= m) z += 2;
			if (z > m)
			{
				printf("-1");
				return 0;
			}
			ans[i] = z;
			visit.insert(z);
			if (++even == n / 2) break;
		}
	}

	printf("%d\n", no);
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}