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
int head[200001],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
} 
int u[400005],v[400005],ta[400005];
int fa[200005],tf[200005],dep[200005];
int cx[2];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
vector<int>res;
void dfs(int no,int f)
{
	tf[no]=f;
	cx[dep[no]=dep[f]^1]++;
	for(int i=head[no];i;i=a[i].nex)
	{
		if(a[i].v!=f)dfs(a[i].v,no);
	}
}
int iset[200005],tot,rp[200005];
int main()
{
	int n,m,k,x,y;
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		u[i]=read();
		v[i]=read();
		x=findf(u[i]);
		y=findf(v[i]);
		if(x!=y)
		{
			fa[x]=y;
			ta[i]=1;
			addb(u[i],v[i]);
			addb(v[i],u[i]);
		}
		else
		{
			if(tot)continue;
			ta[i]=1;
			dfs(u[i],0);
			iset[++tot]=v[i];
			for(int j=v[i];j!=u[i];iset[++tot]=j=tf[j]);
		}
	}
	if(tot==0)
	{
		dfs(1,0);
		int pp=cx[0]>cx[1]?0:1;
		for(register int i=1;i<=n;i++)
		{
			if(dep[i]==pp)res.push_back(i);
		}
		puts("1");
		for(register int i=0;i<(k+1)>>1;i++)
		{
			printf("%d ",res[i]);
		}
		return 0;
	}
	for(int i=1;i<=tot;i++)rp[iset[i]]=i;
	int l=1,r=tot;
	for(int i=1;i<=m;i++)
	{
		if(!ta[i])
		{
			int pu=rp[u[i]];
			int pv=rp[v[i]];
			if(pu>pv)swap(pu,pv);
			if(l<=pu&&pu<=r&&l<=pv&&pv<=r)
			{
				l=pu,r=pv;
			}
		}
	}
	for(int i=l;i<=r;i++)
	{
		res.push_back(iset[i]);
	}
	if(r-l+1<=k)
	{
		printf("2\n%d\n",r-l+1);
		for(int i=0;i<r-l+1;i++)
		{
			printf("%d ",res[i]);
		}
	}
	else
	{
		printf("1\n");
		for(int i=0,j=0;j<(k+1)>>1;i+=2,j++)
		{
			printf("%d ",res[i]);
		}
	}
	return 0;
}