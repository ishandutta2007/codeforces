#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0,cnt1=0;
int dfn[Maxn],low[Maxn],stk[Maxn],tot,top;
int A[Maxn],B[Maxn];
int col[Maxn],r,ans[Maxn];
int d[Maxn];
bool vis[Maxn];
int t[Maxn];
int n,m,h;
void insert(int u,int v)
{
	A[++cnt1]=u,B[cnt1]=v;
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void tarjan(int x)
  {
      dfn[x]=++tot,low[x]=tot;
      vis[x]=true;
      stk[++top]=x;
      for (int q=last[x];q;q=pre[q])
      {
          int v=other[q];
          if (!dfn[v])
          {
tarjan(v);
              low[x]=min(low[x],low[v]);
          } else if (vis[v]) low[x]=min(low[x],dfn[v]);
      }
      if (dfn[x]==low[x])
      {
          vis[x]=false;
          col[x]=++r;
          while (stk[top]!=x)
          {
              col[stk[top]]=r;
              vis[stk[top--]]=false;
          }
--top; }
}
int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for (int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if ((t[u]+1)%h==t[v]) insert(v,u);
		if ((t[v]+1)%h==t[u]) insert(u,v);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++)
		++ans[col[i]];
	for (int i=1;i<=m;i++)
		if (col[A[i]]!=col[B[i]]) ++d[col[B[i]]];
	int anss=n+1,t=0;
	for (int i=1;i<=r;i++)
		if (d[i]==0)
		{
			if (ans[i]<anss)
			{
				anss=ans[i];
				t=i;
			}
		}
	printf("%d\n",anss);
	for (int i=1;i<=n;i++)
		if (col[i]==t) printf("%d ",i);
	printf("\n");
	return 0;
}