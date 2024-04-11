#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long
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
const int maxn=2e5+5;
int n,m,p[maxn];
ll a[maxn],f[maxn],mx,mn,lx,rx;
vector<int> v[maxn],t[maxn];
void dfs(int x,int fa,int dep)
{
	t[dep].push_back(x);m=max(m,dep);p[x]=fa;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=fa)dfs(v[x][i],x,dep+1);
}
int main()
{
	int cas,x;
	cas=read();
	while(cas--)
	{
		n=read();
		m=f[0]=0;
		for(int i=1;i<=n;i++)v[i].clear(),t[i].clear(),f[i]=0;
		for(int i=2;i<=n;i++)x=read(),v[x].push_back(i);
		for(int i=2;i<=n;i++)a[i]=read();
		dfs(1,0,0);
		for(int i=1;i<=m;i++)
		{
			mx=lx=rx=-1e9,mn=1e9;
			for(auto it:t[i])mx=max(mx,a[it]),mn=min(mn,a[it]),lx=max(lx,f[p[it]]-a[it]),rx=max(rx,f[p[it]]+a[it]);
			for(auto it:t[i])f[it]=max(f[p[it]]+max(mx-a[it],a[it]-mn),max(lx+a[it],rx-a[it]));
		}
		for(auto it:t[m])f[0]=max(f[0],f[it]);
		printf("%lld\n",f[0]);
	}
	return 0;
}