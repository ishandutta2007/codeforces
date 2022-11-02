#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
double ans,p[120];
int n,A,b[120],ret[120];
void dfs(int k,int re)
{
	if(k==n)
	{
		double P=0.0;
		for(int i=0;i<(1<<n);i++)
		{
			int ct=0;
			int B=0;
			double te=1.0;
			for(int j=i;j;j-=j&-j)ct++;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					te*=(0.1*ret[j]+p[j]);
				}
				else
				{
					te*=(1.0-0.1*ret[j]-p[j]);
					B+=b[j];
				}
			}
			if(ct*2<=n)
			{
				te=te*A/(double)(A+B);
			}
			P+=te;
		}
	//	if(P>1.0)for(int j=0;j<n;j++)printf("%d ",ret[j]);
		ans=max(ans,P);
		return;
	}
	for(int i=0;i<=re&&p[k]+0.1*i<1.01;i++)
	{
		ret[k]=i;
		dfs(k+1,re-i);
	}
}
int m,i;
int main()
{
	while(~scanf("%d%d%d",&n,&m,&A))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%lf",&b[i],&p[i]);
			p[i]/=100.0;
		}
		ans=0.0;
		dfs(0,m);
		printf("%.8f\n",ans);
	}
}