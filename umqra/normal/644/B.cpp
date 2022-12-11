#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = (int)1e6 + 10;
int tIn[N], d[N];
int q[N];
long long ans[N];
int l = 0, r = 0;

int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	long long curTime = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &tIn[i], &d[i]);
		while (r - l > 0 && curTime <= tIn[i])
		{
			int id = q[l++];
			curTime += d[id];
			ans[id] = curTime;
		}
		curTime = max(curTime, 1LL * tIn[i]);
		if (r - l == b)
			ans[i] = -1;
		else
			q[r++] = i;
	}
	while (r - l > 0)
	{
		int id = q[l++];
		curTime += d[id];
		ans[id] = curTime;
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", ans[i]);
	return 0;
}