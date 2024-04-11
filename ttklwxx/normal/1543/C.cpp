#include<iostream>
#include<cstdio>
#define int long long
#define eps 1e-9
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[200005];
double ans=0;
double v;
void dfs(double c,double m,double p,double gl,int bs)
{
	ans+=p*gl*bs;
	if(p>=1-eps)return;
	//printf("%lf %lf %lf %lf %d\n",c,m,p,gl,bs);
	if(c>eps)
	{ 
	if(c<=v)
	{
		if(m<=eps)
		{
			dfs(0,m,c+p,gl*c,bs+1);
		}
		else
		{
			dfs(0,m+c/2,p+c/2,gl*c,bs+1);
		}
	}
	else
	{
		if(m<=eps)
		{
			dfs(c-v,m,p+v,gl*c,bs+1);
		}
		else
		{
			dfs(c-v,m+v/2,p+v/2,gl*c,bs+1);
		}
	}
	}
	if(m>eps)
	{
	if(m<=v)
	{
		if(c<=eps)
		{
			dfs(c,0,m+p,gl*m,bs+1);
		}
		else
		{
			dfs(c+m/2,0,p+m/2,gl*m,bs+1);
		}
	}
	else
	{
		if(c<=eps)
		{
			dfs(c,m-v,p+v,gl*m,bs+1);
		}
		else
		{
			dfs(c+v/2,m-v,p+v/2,gl*m,bs+1);
		}
	}
	}
}
signed main()
{
	int t;
	double c,m,p;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%lf%lf%lf%lf",&c,&m,&p,&v);
		ans=0;
		dfs(c,m,p,1.0,1);
		printf("%.9lf\n",ans);
	}
	return 0;
}