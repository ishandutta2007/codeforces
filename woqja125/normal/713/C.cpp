#include<stdio.h>
#include<queue>
int a[3001];
int main()
{
	int n, t;
	long long ans = 0;
	std::priority_queue<int> Q; int b;
	scanf("%d%d", &n, &t);
	Q.push(t);
	for(int i=1; i<n; i++)
	{
		scanf("%d", &t); t-=i;
		Q.push(t); b = t;
		while(Q.top() > b)
		{
			ans += Q.top() - b;
			int temp = Q.top();
			Q.pop();
			Q.push(b);
			b = temp;
		}
	}
	printf("%lld", ans);
	return 0;
}