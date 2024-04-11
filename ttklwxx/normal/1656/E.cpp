#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define int long long
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
struct bbian
{
	int u,v,nex;
}a[800004];
int head[100005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int dep[200005];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x);
	}
}
int rd[200005];
signed main()
{
	int t,n,k,now,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)head[i]=0,rd[i]=0;
		tmp=0;
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			addb(x,y);
			addb(y,x);
			rd[x]++;
			rd[y]++;
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)
		{
			if(dep[i]%2==0)printf("%lld ",rd[i]);
			else printf("%lld ",-rd[i]);
		}
	} 
	return 0;
}