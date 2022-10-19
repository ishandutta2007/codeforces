#include<iostream>
#include<cstdio>
#include<queue>
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
}a[2000004],b[2000004];
int head[1000004],tmp;
int headb[1000004],tmpb;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
void addbb(int x,int y)
{
	b[++tmpb].u=x;
	b[tmpb].v=y;
	b[tmpb].nex=headb[x];
	headb[x]=tmp;
}
int uu[1000004],vv[1000004];
int qz[1000004],tp[1000004],cnt,rd[1000004];
int tt[1000004];
queue<int>que;
int main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		uu[i]=read();
		vv[i]=read();
	} 
	for(int i=1;i<=n;i++)qz[i]=read();
	for(int i=1;i<=m;i++)
	{
		if(qz[uu[i]]==qz[vv[i]])
		{
			printf("-1\n");
			return 0; 
		}
		if(qz[uu[i]]<qz[vv[i]])addb(uu[i],vv[i]),rd[vv[i]]++,addbb(vv[i],uu[i]);
		else addb(vv[i],uu[i]),rd[uu[i]]++,addbb(uu[i],vv[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(qz[i]>rd[i]+1)
		{
			printf("-1\n");
			return 0; 
		} 
		for(int j=1;j<=qz[i];j++)tt[j]=0;
		for(int j=headb[i];j;j=b[j].nex)
		{
			tt[qz[b[j].v]]=1;
		}
		for(int j=1;j<=qz[i]-1;j++)
		{
			if(tt[j]==0)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)if(rd[i]==0)
	{
		if(qz[i]!=1)
		{
			printf("-1\n");
			return 0;
		}
		que.push(i);
	}
	int x;
	while(!que.empty())
	{
		x=que.front();
		tp[++cnt]=x;
		que.pop();
		for(int i=head[x];i;i=a[i].nex)
		{
			rd[a[i].v]--;
			if(rd[a[i].v]==0)
			{
				que.push(a[i].v);
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",tp[i]);
	return 0;
}