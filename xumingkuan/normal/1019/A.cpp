#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 5050;
int n, m;
vector<int> a[MAXN];
long long ans, now = 0;
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	int mxs = 0;
	for(int i = 2; i <= m; i++)
	{
		sort(a[i].begin(), a[i].end(), greater<int>());
		for(int j = 0; j < (int)a[i].size(); j++)
			now += a[i][j];
		mxs = max(mxs, (int)a[i].size());
	}
	ans = now;
	int cnt = n;
	for(int i = 0; i < mxs; i++)
	{
		for(int j = 2; j <= m; j++)
			if((int)a[j].size() > i)
			{
				now -= a[j][i];
				cnt--;
				q.push(a[j][i]);
			}
		while(cnt <= i + 1)
		{
			now += q.top();
			q.pop();
			cnt++;
		}
		if(now < ans)
			ans = now;
	}
	printf("%I64d\n", ans);
	return 0;
}