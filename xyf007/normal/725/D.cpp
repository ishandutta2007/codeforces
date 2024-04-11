#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
struct team
{
	int id;
	long long t, w;
	bool operator<(const team a) const
	{
		return t > a.t;
	}
} a[300001];
int n;
priority_queue<long long, vector<long long>, greater<long long> > q;
void checkmin(int &x, int y)
{
	if (x > y)
	{
		x = y;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &a[i].t, &a[i].w);
	}
	long long sum = a[1].t;
	sort(a + 2, a + n + 1);
	int now = 2, ans = n;
	while (1)
	{
		while (now <= n && a[now].t > sum)
		{
			q.push(a[now].w - a[now].t + 1);
			now++;
		}
		checkmin(ans, q.size() + 1);
		if (q.empty() || sum < q.top())
		{
			break;
		}
		else
		{
			sum -= q.top();
			q.pop();
		}
	}
	printf("%d", ans);
	return 0;
}