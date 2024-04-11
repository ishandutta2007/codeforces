#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,f[N],s[N],x[N],y[N],p,c,ans[N],fl;
struct edge
{
	int u,v,w,t;
	edge(){}
	edge(int _u,int _v,int _w,int _t):u(_u),v(_v),w(_w),t(_t){}
	bool operator<(const edge &k)const
	{
		return w>k.w;
	}
}a[N],t[N];
priority_queue<edge>q;
vector<edge>tr[N<<2];
int fa(int x){return x==f[x]?x:fa(f[x]);}
void merge(int u,int v)
{
	u=fa(u),v=fa(v);
	if(u==v)
		return;
	if(s[u]>s[v])
		swap(u,v);
	c-=(s[u]&1)+(s[v]&1);
	f[u]=v,s[v]+=s[u],c+=(s[v]&1);
	p++,x[p]=u,y[p]=v;
}
void undo(int d)
{
	while(p!=d)
	{
		int u=x[p],v=y[p];
		c-=(s[v]&1),f[u]=u,s[v]-=s[u];
		c+=(s[u]&1)+(s[v]&1);
		p--;
	}
}
void add(int k,int l,int r,int a,int b,edge x)
{	
	if(a>b)
		return;
	if(l==a&&r==b)
	{
		tr[k].push_back(x);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) add(k<<1,l,mid,a,b,x);
	else if(a>mid) add(k<<1|1,mid+1,r,a,b,x);
	else add(k<<1,l,mid,a,mid,x),add(k<<1|1,mid+1,r,mid+1,b,x);
}
void dfs(int k,int l,int r,int h)
{
	int d=p;
	for(auto i:tr[k])
	{
		merge(i.u,i.v);
		h=max(h,i.w);
	}
	if(l==r)
	{
		int y=0;
		while(c&&!q.empty())
		{
			edge x=q.top();
			q.pop();
			if(x.t<=l)
			{
				merge(x.u,x.v);
				h=max(h,x.w);
				y++;
				t[y]=x;
			}
		}
		if(!c)
		{
			ans[l]=h;
			for(int i=1;i<=y;i++)
				add(1,1,m,t[i].t,l-1,t[i]);
		}
		else
			ans[l]=-1;
	}
	else
	{
		int mid=l+r>>1;
		dfs(k<<1|1,mid+1,r,h);
		dfs(k<<1,l,mid,h);
	}
	undo(d);
	fl=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i,s[i]=1;
	c=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		a[i].t=i;
		q.push(a[i]);
	}
	dfs(1,1,m,-1);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}