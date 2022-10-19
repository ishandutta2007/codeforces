#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=7000005,inf=1000000000;
struct zh
{
	int p,l,r,h;
	bool operator<(const zh k)const
	{
		return p<k.p;
	}
}a[N*N];
int n,vx,vy,c,tr[M],tag[M],lc[M],rc[M],rt=1;
long long ans;
void update(int &k,int l,int r,int a,int b,int v)
{
	if(!k) k=++c;
	if(l==a&&r==b)
	{
		tr[k]=max(tr[k],v);
		tag[k]=max(tag[k],v);
		return;
	}
	int mid=((long long)l+r)>>1;
	if(b<=mid) update(lc[k],l,mid,a,b,v);
	else if(a>mid) update(rc[k],mid+1,r,a,b,v);
	else update(lc[k],l,mid,a,mid,v),update(rc[k],mid+1,r,mid+1,b,v);
	tr[k]=max(tag[k],min(tr[lc[k]],tr[rc[k]]));
}
int query(int k,int l,int r,int a,int b)
{
	if(!k) return 0;
	if(l==a&&r==b)
		return tr[k];
	int mid=((long long)l+r)>>1;
	if(b<=mid) return max(tag[k],query(lc[k],l,mid,a,b));
	else if(a>mid) return max(tag[k],query(rc[k],mid+1,r,a,b));
	else return max(tag[k],min(query(lc[k],l,mid,a,mid),query(rc[k],mid+1,r,mid+1,b)));
}
int main()
{
	scanf("%d%d%d",&n,&vx,&vy);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c++;
			scanf("%d",&a[c].h);
			a[c].p=inf,a[c].l=inf,a[c].r=-inf;
			for(int x=i-1;x<=i;x++)
			{
				for(int y=j-1;y<=j;y++)
				{
					a[c].p=min(a[c].p,vx*x+vy*y);
					a[c].l=min(a[c].l,vy*x-vx*y);
					a[c].r=max(a[c].r,vy*x-vx*y);
				}
			}
			a[c].r--;
		}
	}
	sort(a+1,a+n*n+1);
	c=0;
	for(int i=1;i<=n*n;i++)
	{
		int v=query(1,1,inf*2,a[i].l+inf,a[i].r+inf);
		ans+=max(0,a[i].h-v);
		update(rt,1,inf*2,a[i].l+inf,a[i].r+inf,a[i].h);
	}
	printf("%I64d\n",ans);
	return 0;
}