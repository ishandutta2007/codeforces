#include<cstdio>
#include<algorithm>
#include<cstring>
#define lc x<<1
#define rc x<<1|1
#define mid ((l+r)>>1)
using namespace std;
struct Tree
{
	int a[6],c[6];
	int tag;
}tree[600005];
int n,m,k,a[150005];
void debug()
{
	for(int i=1;i<=25;i++)
	{
		printf("%d:",i);
		for(int j=1;j<=k;j++)
		  if(tree[i].a[j])printf("(%d,%d) ",tree[i].a[j],tree[i].c[j]);
		printf("\n");
	}
}
Tree merge(Tree a,Tree b)
{
	Tree ans=b;
	ans.tag=0;
	for(int i=1;i<=k;i++)
	{
		if(!a.a[i])continue;
		bool f=0;
		int minv=2147483647,minp;
		for(int j=1;j<=k;j++)
		{
			if(a.a[i]==ans.a[j])
			{
				ans.c[j]+=a.c[i];
				f=1;
				break;
			}
		}
		if(f)continue;
		for(int j=1;j<=k;j++)
		{
			if(!ans.a[j])
			{
				ans.a[j]=a.a[i];
				ans.c[j]=a.c[i];
				f=1;
				break;
			}
			if(ans.c[j]<minv)
			{
				minv=ans.c[j];
				minp=j;
			}
		}
		if(f)continue;
		if(minv<a.c[i])
		{
			ans.a[minp]=a.a[i];
			ans.c[minp]=a.c[i];
		}
		else minv=a.c[i];
		for(int j=1;j<=k;j++)
		{
			ans.c[j]-=minv;
			if(ans.c[j]<=0)ans.a[j]=0;
		}
	}
	return ans;
}
void pushup(int x)
{
	tree[x]=merge(tree[lc],tree[rc]);
}
void pushdown(int x,int l,int r)
{
	if(tree[x].tag)
	{
		tree[lc].tag=tree[rc].tag=tree[x].tag;
		tree[lc].c[1]=mid-l+1,tree[lc].a[1]=tree[x].tag;
		tree[rc].c[1]=r-mid,tree[rc].a[1]=tree[x].tag;
		for(int i=2;i<=k;i++)tree[lc].a[i]=tree[rc].a[i]=0;
		tree[x].tag=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		tree[x].a[1]=a[l];
		tree[x].c[1]=1;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x);
}
Tree query(int x,int l,int r,int from,int to)
{
	if(l>=from&&r<=to)return tree[x];
	Tree ans;
	ans.tag=0;
	for(int i=1;i<=k;i++)ans.a[i]=ans.c[i]=0;
	pushdown(x,l,r);
	if(from<=mid)ans=merge(ans,query(lc,l,mid,from,to));
	if(to>mid)ans=merge(ans,query(rc,mid+1,r,from,to));
	return ans;
}
void update(int x,int l,int r,int from,int to,int v)
{
	if(l>=from&&r<=to)
	{
		tree[x].tag=tree[x].a[1]=v;
		tree[x].c[1]=r-l+1;
		for(int i=2;i<=k;i++)tree[x].a[i]=tree[x].c[i]=0;
		return;
	}
	pushdown(x,l,r);
	if(from<=mid)update(lc,l,mid,from,to,v);
	if(to>mid)update(rc,mid+1,r,from,to,v);
	pushup(x);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	k=100/k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	while(m--)
	{
		int type,l,r,x;
		scanf("%d%d%d",&type,&l,&r);
		if(type==1)
		{
			scanf("%d",&x);
			update(1,1,n,l,r,x);
		}
		if(type==2)
		{
			Tree ans=query(1,1,n,l,r);
			int cnt=0;
			for(int i=1;i<=k;i++)
			  if(ans.a[i])cnt++;
			printf("%d ",cnt);
			for(int i=1;i<=k;i++)
			  if(ans.a[i])printf("%d ",ans.a[i]);
			printf("\n");
		}
	}
	return 0;
}