#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[2000020];
long long h[2000020];
int i,n,m;
long long ans;
int cal(long long x)
{
	return upper_bound(a,a+2*n,x)-lower_bound(a,a+2*n,x);
}
int main()
{
	scanf("%d %d",&n,&m);
	a[n]=h[0]=1;
	for(i=1;i<n;i++)
		a[n+i]=h[i]=13331*h[i-1];
	while(m--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		x--;
		y--;
		a[x]+=h[y];
		a[y]+=h[x];
		a[n+x]+=h[y];
		a[n+y]+=h[x];
	}
	sort(a,a+2*n);
	for(i=0;i<2*n;i++)
		ans+=cal(a[i]);
	printf("%I64d",ans/2-n);
	return 0;
}