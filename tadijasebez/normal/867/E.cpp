#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> pq;
long long sol;
int main()
{
	int n,x,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(!pq.empty() && -pq.top()<x)
		{
			sol+=x+pq.top();
			pq.pop();
			pq.push(-x);
			pq.push(-x);
		}
		else pq.push(-x);
	}
	printf("%lld\n",sol);
	return 0;
}