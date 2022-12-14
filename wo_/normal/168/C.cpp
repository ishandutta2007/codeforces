#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int n,a,d;
	int t[100100],v[100100];
	scanf("%d%d%d",&n,&a,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",t+i,v+i);
	}
	double arrive[100100];
	for(int i=0;i<n;i++)
	{
		if((double)v[i]*v[i]/(2*a)>d)
		{
			double time=sqrt(2.0*d/(double)a);
			arrive[i]=time+t[i];
			continue;
		}
		double dis=d;
		double time=(double)v[i]/a+t[i];
	//	printf("%d::%f\n",i,time);
		dis-=(double)v[i]*v[i]/(2*a);
		time+=(dis/v[i]);
		arrive[i]=time;
	}
	double ans=0;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,arrive[i]);
		printf("%f\n",ans);
	}
	return 0;
}