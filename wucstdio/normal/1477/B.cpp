#include<cstdio>
#include<algorithm>
#include<cstring>
#define lc x<<1
#define rc x<<1|1
#define mid (l+r)/2
using namespace std;
struct Tree
{
	int sum;
	int tag;
}tree[800005];
int t,n,q,a[200005],b[200005];
char s[200005],f[200005];
void pushup(int x)
{
	tree[x].sum=tree[lc].sum+tree[rc].sum;
}
void pushdown(int x,int l,int r)
{
	if(tree[x].tag!=-1)
	{
		tree[lc].tag=tree[rc].tag=tree[x].tag;
		tree[lc].sum=tree[x].tag*(mid-l+1);
		tree[rc].sum=tree[x].tag*(r-mid);
		tree[x].tag=-1;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		tree[x].sum=f[l]-'0';
		tree[x].tag=-1;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x);
	tree[x].tag=-1;
}
int sum(int x,int l,int r,int from,int to)
{
	if(l>=from&&r<=to)return tree[x].sum;
	pushdown(x,l,r);
	int ans=0;
	if(from<=mid)ans+=sum(lc,l,mid,from,to);
	if(to>mid)ans+=sum(rc,mid+1,r,from,to);
	return ans;
}
void update(int x,int l,int r,int from,int to,int v)
{
	if(l>=from&&r<=to)
	{
		tree[x].tag=v;
		tree[x].sum=v*(r-l+1);
		return;
	}
	pushdown(x,l,r);
	if(from<=mid)update(lc,l,mid,from,to,v);
	if(to>mid)update(rc,mid+1,r,from,to,v);
	pushup(x);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s%s",s+1,f+1);
		build(1,1,n);
		for(int i=1;i<=q;i++)scanf("%d%d",&a[i],&b[i]);
		bool flag=1;
		for(int i=q;i>=1;i--)
		{
			int x=sum(1,1,n,a[i],b[i]);
			if((b[i]-a[i]+1)%2==0&&x==(b[i]-a[i]+1)/2)
			{
				flag=0;
				break;
			}
			if(x<=(b[i]-a[i]+1)/2)update(1,1,n,a[i],b[i],0);
			else update(1,1,n,a[i],b[i],1);
		}
		for(int i=1;i<=n;i++)
		{
			if(sum(1,1,n,i,i)!=s[i]-'0')
			{
				flag=0;
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}