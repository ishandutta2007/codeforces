#include <bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return (long long)x*f;
}
int n;
int x[1007],y[1007];
double ans;
double get(double x1,double y1,double x2,double y2,double x3,double y3)
{
	if (abs(x1-x3)>1e-5)
	{
	double ret=(double)((double)(y3-y1)/(x3-x1))*(x2-x1);
	ret=ret+y1-y2;
	ret=abs(ret);
	double ret1=(double)(y3-y1)/(x3-x1);
	ret1=(double)sqrt(1+(double)ret1*ret1);
	ret=(double)ret/(2.0*ret1);
	return ret;
} else 
{
	double ret=(double)abs(x1-x2)/2.0;
	return ret;
}
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	x[n+1]=x[1],y[n+1]=y[1];
	x[n+2]=x[2],y[n+2]=y[2];
	ans=10000000000.0;
	for (int i=1;i<=n;i++)
		ans=min(ans,get(x[i],y[i],x[i+1],y[i+1],x[i+2],y[i+2]));
	printf("%.6lf\n",ans);
	return 0;
}