#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,q,t,a[N],tr[N<<5],lc[N<<5],rc[N<<5],rt[N];
void build(int k,int l,int r)
{
	if(l==r)
		return;
	lc[k]=++t,rc[k]=++t;
	int mid=l+r>>1;
	build(lc[k],l,mid);
	build(rc[k],mid+1,r);
}
int ins(int u,int l,int r,int x,int v)
{
	int k=++t;
	tr[k]=tr[u],lc[k]=lc[u],rc[k]=rc[u];
	if(l==r)
	{
		tr[k]+=v;
		return k;
	}
	int mid=l+r>>1;
	if(x<=mid) lc[k]=ins(lc[k],l,mid,x,v);
	else rc[k]=ins(rc[k],mid+1,r,x,v);
	tr[k]=tr[lc[k]]+tr[rc[k]];
	return k;
}
int query(int k1,int k2,int l,int r)
{
	if(l==r)
		return tr[k2]-tr[k1];
	int mid=l+r>>1;
	if(tr[lc[k2]]-tr[lc[k1]]>tr[rc[k2]]-tr[rc[k1]])
		return query(lc[k1],lc[k2],l,mid);
	else
		return query(rc[k1],rc[k2],mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	rt[0]=++t;
	build(rt[0],1,n);
	for(int i=1;i<=n;i++)
		rt[i]=ins(rt[i-1],1,n,a[i],1);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int s=query(rt[l-1],rt[r],1,n);
		printf("%d\n",max(1,2*s-(r-l+1)));
	}
	return 0;
}