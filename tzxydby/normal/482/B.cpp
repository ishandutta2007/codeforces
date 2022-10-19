#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int tr[N<<3],tag[N<<3];
void pushdown(int k,int l,int r)
{
	tr[k<<1]|=tag[k];
	tag[k<<1]|=tag[k];
	tr[k<<1|1]|=tag[k];
	tag[k<<1|1]|=tag[k];
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
	else return query(k<<1,l,mid,a,mid)&query(k<<1|1,mid+1,r,mid+1,b);
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]|=v;
		tag[k]|=v;
		return;
	}
	if(tag[k])
		pushdown(k,l,r);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=tr[k<<1]&tr[k<<1|1];
}
int l[N],r[N],v[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l[i],&r[i],&v[i]);
		update(1,1,n,l[i],r[i],v[i]);
	}
	for(int i=1;i<=m;i++)
	{
		if(query(1,1,n,l[i],r[i])!=v[i])
		{
			printf("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",query(1,1,n,i,i));
	return 0;
}