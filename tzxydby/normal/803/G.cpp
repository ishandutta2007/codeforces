#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,k,q,c,a[N],rt,tr[N<<7],lc[N<<7],rc[N<<7],tag[N<<7],st[N][17],lg[N],t=1e9;
int mn(int l,int r)
{
	int x=lg[r-l+1];
	return min(st[l][x],st[r-(1<<x)+1][x]);
}
int val(int l,int r)
{
	if(r-l+1>=n)
		return t;
	int x=(l-1)%n+1,y=(r-1)%n+1;
	if(x<=y)
		return mn(x,y);
	else
		return min(mn(x,n),mn(1,y));
}
void pushdown(int k)
{
	if(tag[k]!=-1)
	{
		if(!lc[k]) lc[k]=++c;
		if(!rc[k]) rc[k]=++c;
		tr[lc[k]]=tag[k];
		tag[lc[k]]=tag[k];
		tr[rc[k]]=tag[k];
		tag[rc[k]]=tag[k];
		tag[k]=-1;
	}
}
void update(int &k,int l,int r,int a,int b,int v)
{
	if(!k)
	{
		k=++c;
		tr[k]=val(l,r);
		tag[k]=-1;
	}
	if(l==a&&r==b)
	{
		tr[k]=v;
		tag[k]=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(lc[k],l,mid,a,b,v);
	else if(a>mid) update(rc[k],mid+1,r,a,b,v);
	else update(lc[k],l,mid,a,mid,v),update(rc[k],mid+1,r,mid+1,b,v);
	int vl=lc[k]?tr[lc[k]]:val(l,mid),vr=rc[k]?tr[rc[k]]:val(mid+1,r);
	tr[k]=min(vl,vr);
}
int query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return k?tr[k]:val(l,r);
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) return query(lc[k],l,mid,a,b);
	else if(a>mid) return query(rc[k],mid+1,r,a,b);
	else return min(query(lc[k],l,mid,a,mid),query(rc[k],mid+1,r,mid+1,b));
}
int main()
{
	tr[0]=2e9,tag[0]=-1;
	scanf("%d%d",&n,&k);
	m=n*k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		st[i][0]=a[i];
		t=min(t,a[i]);
	}
	for(int j=1;j<=16;j++)	
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	scanf("%d",&q);
	while(q--)
	{
		int ty;
		scanf("%d",&ty);
		if(ty==1)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			update(rt,1,m,l,r,x);
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",query(rt,1,m,l,r));
		}
	}
	return 0;
}