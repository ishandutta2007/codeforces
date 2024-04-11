#include <stdio.h>
#define ll long long
const int N=100050;
int a[N],b[N],p,n,i;
double max(double a, double b){ return a>b?a:b;}
int main()
{
	scanf("%i %i",&n,&p);
	for(i=1;i<=n;i++) scanf("%i %i",&a[i],&b[i]);
	ll sum=0;
	for(i=1;i<=n;i++) sum+=a[i];
	if(sum<=(ll)p) return printf("-1\n"),0;
	double top=1e14,bot=0,mid;
	bool inf=1;
	while(top-bot>0.00001)
	{
		mid=(top+bot)/2;
		double need=0;
		for(i=1;i<=n;i++) need+=max(mid*a[i]-b[i],0);
		if(need>mid*p) inf=0,top=mid;
		else bot=mid;
	}
	if(inf) printf("-1\n");
	else printf("%.5llf\n",mid);
	return 0;
}