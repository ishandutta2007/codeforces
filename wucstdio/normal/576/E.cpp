#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Query
{
	int l,r;
	int id;
	int col;
	int type;
	int ans;
}a[500005];
struct Edge
{
	int from,to;
	int col,last;
}e[500005];
int n,m,k,q,pa[50000005],sze[50000005];
vector<int>s[2000005];
int st[10000005],top;
int find(int x)
{
	while(x!=pa[x])x=pa[x];
	return x;
}
void merge(int u,int v)
{
	if(u==v)return;
	if(sze[u]<sze[v])swap(u,v);
	pa[v]=u;
	sze[u]+=sze[v];
	st[++top]=v;
}
void ins(int o,int l,int r,int from,int to,int x)
{
	if(l>=from&&r<=to)
	{
		s[o].push_back(x);
		return;
	}
	if(from<=mid)ins(lson,l,mid,from,to,x);
	if(to>mid)ins(rson,mid+1,r,from,to,x);
}
void solve(int o,int l,int r)
{
	int pre=top;
	int x=(int)s[o].size();
	for(int i=0;i<x;i++)
	{
		if(a[s[o][i]].col==0)continue;
		if(a[s[o][i]].type==1)
		{
			int u=e[a[s[o][i]].id].from,v=e[a[s[o][i]].id].to;
			u=2*n*(a[s[o][i]].col-1)+u;
			v=2*n*(a[s[o][i]].col-1)+v;
			merge(find(u),find(v+n));
			merge(find(u+n),find(v));
		}
	}
	if(l==r)
	{
		for(int i=0;i<x;i++)
		{
			if(a[s[o][i]].col==0)continue;
			if(a[s[o][i]].type==0)
			{
				int u=e[a[s[o][i]].id].from,v=e[a[s[o][i]].id].to;
				u=2*n*(a[s[o][i]].col-1)+u;
				v=2*n*(a[s[o][i]].col-1)+v;
				if(find(u)==find(v))
				{
					a[s[o][i]].col=e[a[s[o][i]].id].col;
					u=e[a[s[o][i]].id].from,v=e[a[s[o][i]].id].to;
					u=2*n*(a[s[o][i]].col-1)+u;
					v=2*n*(a[s[o][i]].col-1)+v;
					a[s[o][i]].ans=1;
				}
				if(a[s[o][i]].col==0)continue;
				merge(find(u),find(v+n));
				merge(find(u+n),find(v));
				a[s[o][i]].type=1;
				e[a[s[o][i]].id].col=a[s[o][i]].col;
			}
		}
	}
	else
	{
		for(int i=0;i<x;i++)
		{
			if(a[s[o][i]].col==0)continue;
			if(a[s[o][i]].type==0)
			{
				s[lson].push_back(s[o][i]);
				s[rson].push_back(s[o][i]);
			}
		}
		solve(lson,l,mid);
		solve(rson,mid+1,r);
	}
	while(top!=pre)
	{
		int v=st[top];
		top--;
		sze[pa[v]]-=sze[v];
		pa[v]=v;
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=2*n*k;i++)pa[i]=i,sze[i]=1;
	for(int i=1;i<=m;i++)scanf("%d%d",&e[i].from,&e[i].to);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(e[x].last)a[e[x].last].r=i-1;
		a[i].l=i;
		a[i].col=y;
		a[i].id=x;
		e[x].last=i;
	}
	for(int i=1;i<=m;i++)
	  if(e[i].last)
		a[e[i].last].r=q;
	for(int i=1;i<=q;i++)ins(1,1,q,a[i].l,a[i].r,i);
	solve(1,1,q);
	for(int i=1;i<=q;i++)
	{
		if(a[i].ans)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}