#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (!q.empty() && x > q.top())
		{
			ans += x - q.top();
			q.pop();
			q.push(x);
		}
		q.push(x);
	}
	printf("%lld", ans);
	return 0;
}