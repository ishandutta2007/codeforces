#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=200005,inf=2e9;
struct seg
{
	int a[N];
	pair<int,int> tr[N<<2];
	pair<int,int> mg(pair<int,int>x,pair<int,int>y)
	{
		pair<int,int>z;
		if(x.first<y.first)
		{
			z.first=x.first;
			z.second=min(x.second,y.first);
		}
		else
		{
			z.first=y.first;
			z.second=min(x.first,y.second);
		}
		return z;
	}
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			tr[k]=make_pair(a[l],inf);
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		tr[k]=mg(tr[k<<1],tr[k<<1|1]);
	}
	void update(int k,int l,int r,int x,int v)
	{
		if(l==r)
		{
			tr[k]=make_pair(v,inf);
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) update(k<<1,l,mid,x,v);
		else update(k<<1|1,mid+1,r,x,v);
		tr[k]=mg(tr[k<<1],tr[k<<1|1]);
	}
	pair<int,int> query(int k,int l,int r,int a,int b)
	{
		if(l==a&&r==b)
			return tr[k];
		int mid=l+r>>1;
		if(b<=mid) return query(k<<1,l,mid,a,b);
		else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
		else return mg(query(k<<1,l,mid,a,mid),query(k<<1|1,mid+1,r,mid+1,b));
	}
}t[9];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x,y,c=0,h[9];
		for(int j=0;j<=8;j++)
			h[j]=inf;
		scanf("%d",&x);
		y=x;
		while(y)
		{
			if(y%10)
				h[c]=x;
			y/=10;
			c++;
		}
		for(int j=0;j<=8;j++)
			t[j].a[i]=h[j];
	}
	for(int c=0;c<=8;c++)
		t[c].build(1,1,n);
	while(m--)
	{
		int ty;
		scanf("%d",&ty);
		if(ty==1)
		{
			int i,x,y,c=0,h[9];
			for(int j=0;j<=8;j++)
				h[j]=inf;
			scanf("%d%d",&i,&x);
			y=x;
			while(y)
			{
				if(y%10)
					h[c]=x;
				y/=10;
				c++;
			}
			for(int j=0;j<=8;j++)
				t[j].update(1,1,n,i,h[j]);
		}
		else
		{
			int l,r,ans=inf;
			scanf("%d%d",&l,&r);
			for(int c=0;c<=8;c++)
			{
				pair<int,int> w=t[c].query(1,1,n,l,r);
				int x=w.first,y=w.second;
				if(x==inf||y==inf)
					continue;
				ans=min(ans,x+y);
			}
			if(ans==inf)
				ans=-1;
			printf("%d\n",ans);
		}
	}
	return 0;
}