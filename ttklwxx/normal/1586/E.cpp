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
}a[1000004];
int head[300005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int zy[300005],dis[300005];
int qu[300005],qv[300005];
int sl[300005];
void dfs(int x,int f)
{
	for(int i=head[x];i;i=a[i].nex)
	{
		if(zy[a[i].v]==0)
		{
			dis[a[i].v]=dis[x]+1;
			zy[a[i].v]=x;
			dfs(a[i].v,x);
		}
	}
}
int tans[300005],cnt;
int tans2[300005],cnt2;
void bdfs(int x)
{
	tans[++cnt]=x;
	if(x==1)return;
	bdfs(zy[x]);
}
void bdfs2(int x)
{
	tans2[++cnt2]=x;
	if(x==1)return;
	bdfs2(zy[x]);
}
int main()
{
	int n,m,x,y,sz=0;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		addb(x,y);
		addb(y,x);
	}
	int q;
	q=read();
	for(int i=1;i<=q;i++)
	{
		qu[i]=read();
		qv[i]=read();
		sl[qu[i]]++;
		sl[qv[i]]++;
	}
	for(int i=1;i<=n;i++)if(sl[i]%2!=0)sz++;
	if(sz!=0)
	{
		printf("NO\n");
		printf("%d\n",sz/2);
		return 0;
	}
	printf("YES\n");
	zy[1]=1;
	dfs(1,0);
	for(int i=1;i<=q;i++)
	{
		cnt=0;
		bdfs(qu[i]);
		//for(int j=1;j<=cnt;j++)printf("%d ",tans[j]);
		cnt2=0;
		bdfs2(qv[i]);
		while(tans[cnt]==tans2[cnt2])
		{
			cnt--;
			cnt2--;
		}
		printf("%d\n",cnt+cnt2+1);
		for(int i=1;i<=cnt;i++)printf("%d ",tans[i]);
		printf("%d ",tans[cnt+1]);
		for(int j=cnt2;j>=1;j--)printf("%d ",tans2[j]);
		printf("\n");
	}
	return 0;
}