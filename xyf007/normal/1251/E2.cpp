#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int t, n, m;
vector<int> v[200001];
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			int m, p;
			scanf("%d%d", &m, &p);
			v[m].push_back(p);
		}
		long long ans = 0;
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = n; i >= 1; i--)
		{
			for (auto j : v[i])
			{
				q.push(j);
			}
			while ((int)q.size() > n - i)
			{
				ans += q.top();
				q.pop();
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}