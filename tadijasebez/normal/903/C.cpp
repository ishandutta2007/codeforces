#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int> pq;
const int N=5005;
int a[N];
int main()
{
	int n,sol=0,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),pq.push(a[i]);
	sort(a+1,a+1+n);
	for(i=n;i;i--)
	{
		while(!pq.empty() && pq.top()>=a[i]) pq.pop(),sol++;
		if(!pq.empty()) pq.pop();
	}
	printf("%i\n",sol);
	return 0;
}