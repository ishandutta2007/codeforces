#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
double x[100005],y[100005],maxr;
int n;
bool judge(double rr)
{
	double maxl=-1e200;
	double minr=1e200;
	for(int i=1;i<=n;i++)
	{
		double len=sqrt((long double)(2*rr-y[i])*(y[i]));
//		printf("%lf %lf\n",x[i]-len,x[i]+len);
		maxl=max(maxl,x[i]-len);
		minr=min(minr,x[i]+len);
	}
//	exit(0);
	if(maxl>minr)return 0;
	else return 1;
}
int main()
{
	scanf("%d",&n);
	scanf("%lf%lf",&x[1],&y[1]);
	bool ff=y[1]>0;
	maxr=y[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
		if(ff&&y[i]<0||!ff&&y[i]>0)
		{
			printf("-1\n");
			return 0;
		}
		if(ff)maxr=max(maxr,y[i]);
		else maxr=min(maxr,y[i]);
	}
	if(!ff)
	{
		maxr=-maxr;
		for(int i=1;i<=n;i++)
		  y[i]=-y[i];
	}
	double l=maxr/2,r=1e14;
	for(int i=1;i<=200;i++)
	{
		double mid=(l+r)/2;
		if(judge(mid))r=mid;
		else l=mid;
	}
	printf("%lf\n",(l+r)/2);
	return 0;
}