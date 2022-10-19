#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int tr[N<<3],tag[N<<3],a[N],dp[N],lst[N];
void build(int k,int l,int r)
{
	tr[k]=tag[k]=0;
	if(l==r)
	{
		tr[k]=dp[l-1];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
void pushdown(int k,int l,int r)
{
	tr[k<<1]+=tag[k];
	tag[k<<1]+=tag[k];
	tr[k<<1|1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
int query(int k,int l,int r,int a,int b)
{
	if(tag[k])
		pushdown(k,l,r);
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b); 
	else return max(query(k<<1,l,mid,a,mid),query(k<<1|1,mid+1,r,mid+1,b));
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		tag[k]+=v;
		return;
	}
	if(tag[k])
		pushdown(k,l,r);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)
	{
		build(1,1,n);
		memset(lst,0,sizeof(lst));
		for(int j=1;j<=n;j++)
		{
			update(1,1,n,lst[a[j]]+1,j,1);
			lst[a[j]]=j;
			dp[j]=query(1,1,n,1,j);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}