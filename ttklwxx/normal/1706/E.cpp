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
int fa[200005],siz[200005];
int dep[200005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
vector<int>v[200005],bq[200005];
int tf[200005],tb[200005];
void dfs(int x,int f)
{
	//printf("vis:%d %d\n",x,f);
	dep[x]=dep[f]+1;
	tf[x]=f;
	for(int i=0;i<v[x].size();i++)
	{
		tb[v[x][i]]=bq[x][i];
		dfs(v[x][i],x);
	}
}
int qans[200005];
int maxn[200005][20];
int findlj(int x,int y)
{
	int ans=0;
	while(dep[x]>dep[y])
	{
		ans=max(ans,tb[x]);
		x=tf[x];
	}
	while(dep[y]>dep[x])
	{
		ans=max(ans,tb[y]);
		y=tf[y];
	}
	while(x!=y)
	{
		ans=max(ans,tb[x]);
		ans=max(ans,tb[y]);
		x=tf[x];
		y=tf[y];
	}
	return ans;
}
int logg[200005];
int findmax(int l,int r)
{
	int k=logg[r-l+1];
	return max(maxn[l][k],maxn[r-(1<<k)+1][k]);
}
int main()
{
	logg[1]=0;
	for(int i=2;i<=200000;i++)logg[i]=logg[i>>1]+1;
	int t,n,m,q,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		q=read();
		for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1,v[i].clear(),bq[i].clear();
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			x=findf(x);
			y=findf(y);
			if(x==y)continue;
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y;
			siz[y]+=siz[x];
			v[y].push_back(x);
			bq[y].push_back(i);
		}
		dfs(findf(1),0);
		for(int i=1;i<=n-1;i++)
		{
			qans[i]=findlj(i,i+1);
			maxn[i][0]=qans[i];
		}
		for(int j=1;j<=19;j++)
		{
			for(int i=1;i<=n-1-(1<<j)+1;i++)
			{
				maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
			}
		}
		for(int i=1;i<=q;i++)
		{
			x=read();
			y=read();
			if(x==y)printf("0 ");
			else printf("%d ",findmax(x,y-1));
		}
		printf("\n");
	}
	return 0;
}