#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,px,py;
int x[Maxn],y[Maxn];
long long mx=0;
double mn=100000000.0;
double ans;
double calc(int a,int b)
{
	if (x[a]>x[b]) swap(a,b);
	double res=100000000.0;
	double A=(double)(y[a]-y[b]);
	double B=(double)(x[b]-x[a]);
	double C=(-A*x[a]-B*y[a]);
	double AA=B,BB=-A;
	double CC=-AA*px-BB*py;
	res=min(res,sqrt(1.0*(1LL*(x[a]-px)*(x[a]-px)+1LL*(y[a]-py)*(y[a]-py))));
	res=min(res,sqrt(1.0*(1LL*(x[b]-px)*(x[b]-px)+1LL*(y[b]-py)*(y[b]-py))));
	double xx=(B*CC-BB*C)/(A*BB-AA*B);
	if (xx>=x[a]&&xx<=x[b])
		res=min(res,fabs((double)(A*px+B*py+C)/(double)sqrt(A*A+B*B)));
	return res;
}
int main()
{
	n=read(),px=read(),py=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
		mx=max(mx,1LL*(x[i]-px)*(x[i]-px)+1LL*(y[i]-py)*(y[i]-py));
	}
	x[n+1]=x[1],y[n+1]=y[1];
	for (int i=1;i<=n;i++)
		mn=min(mn,calc(i,i+1));
	mn=mn*mn;
	ans=M_PI*(mx-mn);
	printf("%.9lf\n",ans);
	return 0;
}