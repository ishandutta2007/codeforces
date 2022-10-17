#include <iostream>
#include <cstdio>
#include <queue>
#define maxn 200005
using namespace std;
int n;
long long a[maxn];
priority_queue<long long> q;
int main()
{
	scanf("%d", &n);
	int cnt = 0;
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		cnt++;
		sum += a[i];
		q.push(-a[i]);
		if(sum < 0)
		{
			long long x = q.top();
			q.pop();
			sum += x;
			cnt--;
		}
	}
	printf("%d", cnt);
	return 0;
}