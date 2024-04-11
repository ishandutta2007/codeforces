#include<iostream>
#include<cstdio>
#include<vector>
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
int head[200005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int fa[200005];
bool flag;
bool par[200005];
void dfs(int x,int f)
{
	fa[x]=f;
	int sth[2];
	sth[0]=sth[1]=0;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x);
		sth[par[a[i].v]]++;
	}
	if(x!=1)
	{
		if(sth[0]>=sth[1])par[x]=1;
		else par[x]=0;
		sth[par[x]]++;
	}
//	printf("vis:%d %d\n",sth[0],sth[1]); 
	if(sth[1]-sth[0]<0||sth[1]-sth[0]>1)
	{
		flag=false;
	} 
}
void solve(int x)
{
	vector<int>sth[2];
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v!=fa[x])
		{
			sth[par[a[i].v]].push_back(a[i].v);
		}
		else
		{
			sth[par[x]].push_back(a[i].v);
		}
	}
	int tsl=sth[0].size()+sth[1].size(),now=tsl%2;
	for(int i=0;i<tsl;i++)
	{
		int gre=sth[now].back();
		if(gre==fa[x])
		{
			printf("%d %d\n",x,fa[x]);
		}
		else solve(gre);
		sth[now].pop_back();
		now^=1;
	}
}
int main()
{
	int t,n,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			head[i]=0;
			fa[i]=0;
			par[i]=0;
		}
		tmp=0;
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			addb(x,y);
			addb(y,x);
		}
		flag=true;
		dfs(1,0);
		if(flag==false)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		solve(1);
	}
	return 0;
}