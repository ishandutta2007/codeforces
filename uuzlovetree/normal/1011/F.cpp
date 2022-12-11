#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n;
int tp[maxn],fa[maxn],son[maxn][2],val[maxn];
void dfs(int u)
{
	if(tp[u]==1)return;
	if(son[u][0])dfs(son[u][0]);
	if(son[u][1])dfs(son[u][1]);
	if(tp[u]==2)val[u]=val[son[u][0]]^1;
	if(tp[u]==3)val[u]=val[son[u][0]]&val[son[u][1]];
	if(tp[u]==4)val[u]=val[son[u][0]]|val[son[u][1]];
	if(tp[u]==5)val[u]=val[son[u][0]]^val[son[u][1]];
}
int anc[maxn][22];
bool Ans[2][maxn][22];
inline int get(int u,int v,int x)
{
	if(tp[u]==2)return x^1;
	int ls=son[u][0],rs=son[u][1];
	if(rs==v)swap(ls,rs);
	if(tp[u]==3)return x&val[rs];
	if(tp[u]==4)return x|val[rs];
	if(tp[u]==5)return x^val[rs];
}
void init()
{
	for(int i=2;i<=n;++i)
	{
		anc[i][0]=fa[i];
		Ans[0][i][0]=get(fa[i],i,0);
		Ans[1][i][0]=get(fa[i],i,1);
	}
	for(int j=1;j<=20;++j)
	{
		for(int i=1;i<=n;++i)
		{
			anc[i][j]=anc[anc[i][j-1]][j-1];
			Ans[0][i][j]=Ans[Ans[0][i][j-1]][anc[i][j-1]][j-1];
			Ans[1][i][j]=Ans[Ans[1][i][j-1]][anc[i][j-1]][j-1];
		}
	}
}
int query(int u)
{
	int ans=val[u]^1;
	for(int i=20;i>=0;--i)if(anc[u][i])
	{
		ans=Ans[ans][u][i];
		u=anc[u][i];
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		char opt[5];
		scanf("%s",opt);
		int x,y;
		if(opt[0]=='I')
		{
			tp[i]=1;
			scanf("%d",&x);
			val[i]=x;
		}
		if(opt[0]=='N')
		{
			tp[i]=2;
			scanf("%d",&x);
			son[i][0]=x;fa[x]=i;
		}
		if(opt[0]=='A')
		{
			tp[i]=3;
			scanf("%d%d",&x,&y);
			son[i][0]=x;son[i][1]=y;fa[x]=fa[y]=i;
		}
		if(opt[0]=='O')
		{
			tp[i]=4;
			scanf("%d%d",&x,&y);
			son[i][0]=x;son[i][1]=y;fa[x]=fa[y]=i;
		}
		if(opt[0]=='X')
		{
			tp[i]=5;
			scanf("%d%d",&x,&y);
			son[i][0]=x;son[i][1]=y;fa[x]=fa[y]=i;
		}
	}
	dfs(1);
	init();
	for(int i=1;i<=n;++i)if(tp[i]==1)printf("%d",query(i));
	puts("");
	return 0;
}