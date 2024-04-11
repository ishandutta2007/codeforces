#include<iostream>
#include<cstdio>
#include<cstring>
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
bool vis[200005];
bool cz[200005];
struct bbian
{
	int u,v,nex;
}a[800004];
int head[200005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int mind[200005],dep[200005];
bool flag;
void dfs(int x,int f)
{
	if(f!=0)dep[x]=dep[f]+1;
	else dep[x]=0;
	if(cz[x])mind[x]=dep[x];
	else mind[x]=1000000000;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x);
		mind[x]=min(mind[x],mind[a[i].v]);
	}
}
bool fz[200005];
int rd[200005];
int ans=0;
void findda(int x,int f)
{
	if(mind[x]<=2*dep[x]&&fz[f]==false)ans++;
	if(mind[x]<=2*dep[x])fz[x]=true;
	else fz[x]=fz[f];
	//printf("vis:%d %d\n",x,(int)fz[x]);
	if(x!=1&&rd[x]==1&&fz[x]==false)flag=false;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		findda(a[i].v,x);
	}
}
int xx[200005];
signed main()
{
	int t,n,k,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=k;i++)
		{
			xx[i]=read();
			cz[xx[i]]=true;
		}
		flag=true;
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			rd[x]++;
			rd[y]++;
			addb(x,y);
			addb(y,x);
		}
		dfs(1,0);
		ans=0;
		findda(1,0);
		if(flag==false)
		{
			printf("YES\n");
			for(int i=1;i<=n;i++)
			{
				cz[i]=false;
				fz[i]=false;
				head[i]=0;
				rd[i]=0;
				dep[i]=0;
				mind[i]=0;
			}
			tmp=0;
			continue;
		}
		printf("NO\n");
		for(int i=1;i<=n;i++)
		{
			cz[i]=false;
			fz[i]=false;
			head[i]=0;
			rd[i]=0;
			dep[i]=0;
			mind[i]=0;
		}
		tmp=0;
		
	}
	return 0;
}