#include <stdio.h>
#include <queue>
using namespace std;
const int N=200050;
priority_queue<int> pq,pq1;
int p[N];
int main()
{
	int n,q,l,r,i,x;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&x),pq.push(x);
	for(i=1;i<=q;i++) scanf("%i %i",&l,&r),r++,p[l]++,p[r]--;
	int t=0;
	for(i=1;i<=n;i++) t+=p[i],pq1.push(t);
	long long sol=0;
	while(n --> 0) sol+=1ll*pq.top()*pq1.top(),pq.pop(),pq1.pop();
	printf("%lld\n",sol);
	return 0;
}