#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[500005],u[500005],v[500005],op[500005],x[500005],ans[500005],p[500005],fa[500005],sz[500005],l[500005],r[500005],mn[500005],mx[500005],w[500005];
pair <int,int> T[500005];
vector <int> qwq[500005];
struct stree
{
	int l,r,mx,pos;
}t[1000005];
inline void pushup(int now)
{
	t[now].mx=max(t[now*2].mx,t[now*2+1].mx);
	if(t[now].mx==t[now*2].mx) t[now].pos=t[now*2].pos;
	else t[now].pos=t[now*2+1].pos;
}
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r;
	if(l==r)
	{
		t[now].mx=w[l],t[now].pos=l;
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	pushup(now);
}
inline void change(int now,int x,int d)
{
	if(t[now].l==t[now].r)
	{
		t[now].mx=d;
		return ;
	}
	if(t[now*2].r>=x) change(now*2,x,d);
	else change(now*2+1,x,d);
	pushup(now);
}
inline int query(int now,int l,int r)
{
	if(t[now].l==l&&t[now].r==r) return t[now].pos;
	if(t[now*2].r>=r) return query(now*2,l,r);
	else if(t[now*2+1].l<=l) return query(now*2+1,l,r);
	else
	{
		int x=query(now*2,l,t[now*2].r),y=query(now*2+1,t[now*2+1].l,r);
		if(w[x]>w[y]) return x;
		else return y;
	}
}
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]); 
}
inline void mg(int x,int y)
{
	x=ff(x),y=ff(y);
	if(x==y) return;
	mn[x]=min(mn[x],mn[y]),mx[x]=max(mx[x],mx[y]);
	fa[y]=x;
}
inline void merge(int x,int y)
{
	x=ff(x),y=ff(y);
	if(x==y) return;
	if(sz[x]>sz[y]) swap(x,y);
	for(auto t:qwq[x]) p[t]+=sz[y];
	for(auto t:qwq[x]) qwq[y].push_back(t);
	qwq[x].clear(),sz[y]+=sz[x],sz[x]=0;
	fa[x]=y;
}
int main(int argc, char** argv) {
	int n,m,q;
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[i]=1,fa[i]=i,sz[i]=1,qwq[i].push_back(i);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u[i],&v[i]),T[i]={q+1,i};
	for(int i=1;i<=q;i++)
		scanf("%d%d",&op[i],&x[i]);
	for(int i=1;i<=q;i++)
		if(op[i]==2) T[x[i]].first=min(T[x[i]].first,i);
	sort(T+1,T+m+1);
	for(int i=m;i>=1;i--)
		merge(u[T[i].second],v[T[i].second]);
	for(int i=1;i<n;i++) merge(i,i+1);
	for(int i=1;i<=n;i++) w[p[i]]=a[i];
	for(int i=1;i<=n;i++) fa[i]=i,mn[i]=p[i],mx[i]=p[i];
	int now=q;
	for(int i=m;i>=0;i--)
	{
		while(now>T[i].first)
		{
			l[now]=mn[ff(x[now])];
			r[now]=mx[ff(x[now])];
			now--;
		}
		mg(u[T[i].second],v[T[i].second]);
	}
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		if(op[i]==1)
		{
			int t=query(1,l[i],r[i]);
			printf("%d\n",w[t]);
			w[t]=0,change(1,t,0);
		}
	}
	return 0;
}