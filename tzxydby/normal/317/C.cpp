#include<bits/stdc++.h>
using namespace std;
const int N=305;
struct zyb
{
	int u,v,d;
	zyb(){}
	zyb(int _u,int _v,int _d):u(_u),v(_v),d(_d){}
};
int n,m,k,a[N],b[N],c[N];
vector<int>e[N],p;
vector<zyb>ans;
int dfs(int u,int t)
{
	c[u]=1;
	p.push_back(u);
	if((t&&a[u]<b[u])||(!t&&a[u]>b[u]))
		return u;
	for(auto v:e[u])
	{
		if(!c[v])
		{
			int x=dfs(v,t);
			if(x!=-1)
				return x;
		}
	}
	p.pop_back();
	return -1;
}
void sol(int s,int t,int d)
{
	p.pop_back();
	if(s==t)
		return;
	int u=p.back(),f=min(a[u],d);
	ans.push_back(zyb(u,t,f));
	a[u]-=f;
	a[t]+=f;
	sol(s,u,d);
	ans.push_back(zyb(u,t,d-f));
	a[u]-=d-f;
	a[t]+=d-f;
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		while(a[i]!=b[i])
		{
			for(int j=1;j<=n;j++)
				c[j]=0;
			int t=(a[i]>b[i]),v=dfs(i,t);
			if(v==-1)
			{
				puts("NO");
				return 0;
			}
			if(t)
				sol(i,v,min(a[i]-b[i],b[v]-a[v]));
			else
			{
				reverse(p.begin(),p.end());
				sol(v,i,min(a[v]-b[v],b[i]-a[i]));
			}
		}
	}
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%d %d %d\n",i.u,i.v,i.d);
	return 0;
}