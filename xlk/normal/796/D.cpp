#include <bits/stdc++.h>
using namespace std;
int n, k, p;
int d[300020];
int x[300020];
int y[300020];
vector<int> a[300020];
queue<int> q;
int main()
{
	scanf("%d%d%*d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &p);
		if (d[p] > 0)
		{
			i--;
			k--;
			continue;			
		}
		d[p] = p;
		q.push(p);
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		a[x[i]].push_back(y[i]);
		a[y[i]].push_back(x[i]); 
	}
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (int i: a[u])
		{
			if (d[i] == 0)
			{
				d[i] = d[u];
				q.push(i);
			}
		}
	}
	printf("%d\n", k - 1);
	for (int i = 1; i < n; i++)
	{
		if (d[x[i]] != d[y[i]])
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}