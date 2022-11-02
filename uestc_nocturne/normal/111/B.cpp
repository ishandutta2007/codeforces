#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
int p[V],vis[V],pt;
void init()
{
	memset(vis,0,sizeof(vis));pt=0;
	int i,j;
	for(i=2;i<=100010;i++)
	{
		if(vis[i])continue;
		p[pt++]=i;
		for(j=2;j*i<=100010;j++)
		vis[i*j]=1;
	}
}
int last[V],fac[V],i,j,n,x,y,ret,t;
int main()
{
	init();
	while(~scanf("%d",&n))
	{
		memset(last,-1,sizeof(last));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);t=0;
			for(j=1;j*j<=x;j++)
			{
				if(x%j==0)
				{
					fac[t++]=j;
					if(j*j!=x)fac[t++]=x/j;
				}
			}
			ret=0;
		//	for(j=0;j<t;j++)printf("%d ",fac[j]);puts("");
			for(j=0;j<t;j++)
			{
				if(last[fac[j]]<i-y)ret++;
				last[fac[j]]=i;
			}
			printf("%d\n",ret);
		}
	}
}