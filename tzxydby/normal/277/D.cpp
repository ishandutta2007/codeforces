#include<bits/stdc++.h>
using namespace std;
const int N=1605;
const long double eps=1e-9;
struct node
{
	int f1,f2,t1,t2;
	long double b;
	bool operator<(const node k)const
	{
		return t2*b/(1-b)>k.t2*k.b/(1-k.b);
	}
}a[N];
int n,t,x;
long double f[N][N],g[N][N],p[N][N];
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		double v;
		scanf("%d%d%d%d%lf",&a[i].f1,&a[i].f2,&a[i].t1,&a[i].t2,&v);
		a[i].b=v;
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=t;j++)
			f[i][j]=-1e18;
	f[0][0]=0,p[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=t;j++)
		{
			f[i][j]=f[i-1][j];
			g[i][j]=g[i-1][j];
			p[i][j]=p[i-1][j];
			if(j>=a[i].t1)
			{
				if(fabs(f[i-1][j-a[i].t1]+a[i].f1-f[i][j])<eps)
				{
					if(g[i-1][j-a[i].t1]+a[i].t1<g[i][j]-eps)
					{
						g[i][j]=g[i-1][j-a[i].t1]+a[i].t1;
						p[i][j]=p[i-1][j-a[i].t1];
					}
				}
				if(f[i-1][j-a[i].t1]+a[i].f1>f[i][j]+eps)
				{
					f[i][j]=f[i-1][j-a[i].t1]+a[i].f1;
					g[i][j]=g[i-1][j-a[i].t1]+a[i].t1;
					p[i][j]=p[i-1][j-a[i].t1];
				}
			}
			if(j>=a[i].t1+a[i].t2)
			{
				int k=i-1,l=j-a[i].t1-a[i].t2;
				double p2=p[k][l]*a[i].b,p1=g[k][l]+a[i].t1+a[i].t2*(1.0-p2);
				if(fabs(f[k][l]+a[i].f1+a[i].f2*(1.0-a[i].b)-f[i][j])<eps)
				{
					if(p1<g[i][j]-eps)
					{
						g[i][j]=p1;
						p[i][j]=p2;
					}
				}
				if(f[k][l]+a[i].f1+a[i].f2*(1.0-a[i].b)>f[i][j]+eps)
				{
					f[i][j]=f[k][l]+a[i].f1+a[i].f2*(1.0-a[i].b);
					g[i][j]=p1;
					p[i][j]=p2;
				}
			}
		}
	}
	for(int j=1;j<=t;j++)
		if(f[n][j]>f[n][x]+eps||(fabs(f[n][j]-f[n][x])<eps&&g[n][j]<g[n][x]-eps))
			x=j;
	double a1=f[n][x],a2=g[n][x];
	printf("%.10lf %.10lf\n",a1,a2);
	return 0;
}