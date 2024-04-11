#include <stdio.h>
#include <queue>
using namespace std;
priority_queue< pair<int,int> > pq;
int a[300050];
int sol[300050];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=k;i++) pq.push(make_pair(a[i],i));
	long long ans=0;
	for(i=k+1;i<=n+k;i++)
	{
		if(i<=n) pq.push(make_pair(a[i],i));
		ans+=1ll*pq.top().first*(i-pq.top().second);
		sol[pq.top().second]=i;
		pq.pop();
	}
	printf("%lld\n",ans);
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	return 0;
}