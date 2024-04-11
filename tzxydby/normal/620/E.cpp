#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int tag[N<<2],cnt,s[N],t[N],ar[N],p[N],n,m;
long long tr[N<<2];
vector<int>e[N];
void dfs(int u,int f)
{
	cnt++;
	s[u]=cnt,p[cnt]=u;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
	t[u]=cnt;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=1LL<<ar[p[l]];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=tr[k<<1]|tr[k<<1|1];
}
void pushdown(int k)
{
	if(tag[k])
	{
		tr[k<<1]=tr[k<<1|1]=tr[k];
		tag[k<<1]=tag[k<<1|1]=1;
		tag[k]=0;
	}
}
void update(int k,int l,int r,int a,int b,long long v)
{                              
	if(l==a&&r==b)
	{
		tr[k]=v;
		tag[k]=1;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=tr[k<<1]|tr[k<<1|1];
}
long long query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return query(k<<1,l,mid,a,mid)|query(k<<1|1,mid+1,r,mid+1,b);
}
int count(long long x)
{
	int s=0;
	while(x)
	{
		s++;
		x-=x&(-x);	
	} 
	return s;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&ar[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	build(1,1,n);
	while(m--)
	{
		int ty;
		scanf("%d",&ty);
		if(ty==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			update(1,1,n,s[x],t[x],1LL<<y);
		}
		if(ty==2)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",count(query(1,1,n,s[x],t[x]))); 
		}
	}
	return 0;
}