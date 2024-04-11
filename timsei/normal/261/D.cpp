using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define lowbit(x) (x&(-x))
#define F(i,a,b) for(int i=a;i<=b;i++)
#define r(x) scanf("%d",&x)
#define N 200001
int k,n,maxb,t;
int a[N],S[N];
int ans[N];
bool vis[N];
int maxl;
void add(int x,int v)
{
	for(int i=x;i<=maxb;i+=lowbit(i)) S[i]=max(S[i],v);
}
int sum(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	{
		res=max(res,S[i]);
	}
	return res;
}
int main()
{
	r(k);r(n);r(maxb);r(t);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++) scanf("%d",&a[j]);
		maxl=0;
		if(t>=maxb)
		{
			memset(vis,0,sizeof(vis));
			for(int p=1;p<=n;p++)
			{
				if(!vis[a[p]])
				{
					maxl++;
					vis[a[p]]=1;
				}
			}
			printf("%d\n",maxl);
			continue;
		}
		memset(S,0,sizeof(S));
		memset(ans,0,sizeof(ans));
		for(int r=1;r<=t;r++)
		{
			for(int l=1;l<=n;l++)
			{
				int it=sum(a[l]-1)+1;
				int hh=ans[a[l]];
				ans[a[l]]=max(ans[a[l]],it);
				if(ans[a[l]]!=hh)add(a[l],it);
			}
		}
		maxl=-1;
		for(int j=1;j<=maxb;j++) maxl=max(maxl,ans[j]);
		printf("%d\n",maxl);continue;
	}
}