#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Tree
{
	int gcd;
}tree[2000005];
int n,m,a[500005];
int gcd(int a,int b)
{
	if(a==0)return b;
	if(a>b)return gcd(b,a);
	return gcd(b%a,a);
}
void pushup(int o)
{
	tree[o].gcd=gcd(tree[lson].gcd,tree[rson].gcd);
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].gcd=a[l];
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
}
int ans=0;
void query(int o,int l,int r,int from,int to,int d)
{
	if(ans>1)return;
	if(l>=from&&r<=to)
	{
		if(tree[o].gcd%d==0)return;
		if(l==r)ans++;
		else if(tree[lson].gcd%d==0)query(rson,mid+1,r,from,to,d);
		else if(tree[rson].gcd%d==0)query(lson,l,mid,from,to,d);
		else ans=2;
		return;
	}
	if(from<=mid)query(lson,l,mid,from,to,d);
	if(to>mid)query(rson,mid+1,r,from,to,d);
}
void change(int o,int l,int r,int p,int x)
{
	if(l==r)
	{
		tree[o].gcd=x;
		return;
	}
	if(p<=mid)change(lson,l,mid,p,x);
	else change(rson,mid+1,r,p,x);
	pushup(o);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			ans=0;
			query(1,1,n,l,r,x);
			if(ans>=2)printf("NO\n");
			else printf("YES\n");
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			change(1,1,n,x,y);
		}
	}
	return 0;
}