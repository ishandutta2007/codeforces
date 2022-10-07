#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lc x<<1
#define rc x<<1|1
#define mid ((l+r)>>1)
using namespace std;
const int INF=2147483647;
struct Tree
{
	int mx,t,se;
	ll num,sum;
	int add,val;
}tree[600005];
int n,m,a[300005],pos[300005];
ll ans[150005];
void pushup(int x)
{
	tree[x].mx=max(tree[lc].mx,tree[rc].mx);
	tree[x].se=tree[lc].mx==tree[rc].mx?max(tree[lc].se,tree[rc].se):max(min(tree[lc].mx,tree[rc].mx),max(tree[lc].se,tree[rc].se));
	tree[x].t=0;
	if(tree[lc].mx==tree[x].mx)tree[x].t+=tree[lc].t;
	if(tree[rc].mx==tree[x].mx)tree[x].t+=tree[rc].t;
	tree[x].sum=tree[lc].sum+tree[rc].sum;
	tree[x].num=tree[lc].num+tree[rc].num;
}
void pushdown(int x)
{
	if(tree[x].add)
	{
		int v=tree[x].add;
		if(tree[lc].num)
		{
			tree[lc].add+=v,tree[lc].mx+=v;
			if(tree[lc].val!=INF)tree[lc].val+=v;
			if(tree[lc].se!=-INF)tree[lc].se+=v;
			tree[lc].sum+=v*tree[lc].num;
		}
		if(tree[rc].num)
		{
			tree[rc].add+=v,tree[rc].mx+=v;
			if(tree[rc].val!=INF)tree[rc].val+=v;
			if(tree[rc].se!=-INF)tree[rc].se+=v;
			tree[rc].sum+=v*tree[rc].num;
		}
		tree[x].add=0;
	}
	if(tree[x].val!=INF)
	{
		int v=tree[x].val;
		if(tree[lc].num)
		{
			tree[lc].val=min(tree[lc].val,v);
			if(tree[lc].val<tree[lc].mx)
			{
				tree[lc].sum-=(tree[lc].mx-tree[lc].val)*tree[lc].t;
				tree[lc].mx=tree[lc].val;
			}
		}
		if(tree[rc].num)
		{
			tree[rc].val=min(tree[rc].val,v);
			if(tree[rc].val<tree[rc].mx)
			{
				tree[rc].sum-=(tree[rc].mx-tree[rc].val)*tree[rc].t;
				tree[rc].mx=tree[rc].val;
			}
		}
		tree[x].val=INF;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		tree[x].num=tree[x].sum=tree[x].add=tree[x].mx=tree[x].t=0;
		tree[x].se=-INF;
		tree[x].val=INF;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int p)
{
	if(l==r)
	{
		tree[x].mx=m;
		tree[x].num=1;
		tree[x].sum=m;
		tree[x].t=1;
		return;
	}
	pushdown(x);
	if(p<=mid)update(lc,l,mid,p);
	else update(rc,mid+1,r,p);
	pushup(x);
}
void add(int x,int l,int r,int from,int to,int v)
{
	if(from>to)return;
	if(!tree[x].num)return;
	if(l>=from&&r<=to)
	{
		tree[x].add+=v;
		if(tree[x].val!=INF)tree[x].val+=v;
		tree[x].mx+=v;
		if(tree[x].se!=-INF)tree[x].se+=v;
		tree[x].sum+=tree[x].num*v;
		return;
	}
	pushdown(x);
	if(from<=mid)add(lc,l,mid,from,to,v);
	if(to>mid)add(rc,mid+1,r,from,to,v);
	pushup(x);
}
void setmax(int x,int l,int r,int from,int to,int v)
{
	if(from>to)return;
	if(!tree[x].num)return;
	if(l>=from&&r<=to)
	{
		if(v>=tree[x].mx)return;
		if(v>tree[x].se)
		{
			tree[x].sum-=(tree[x].mx-v)*tree[x].t;
			tree[x].mx=v;
			tree[x].val=v;
			return;
		}
		pushdown(x);
		setmax(lc,l,mid,from,to,v);
		setmax(rc,mid+1,r,from,to,v);
		pushup(x);
		return;
	}
	pushdown(x);
	if(from<=mid)setmax(lc,l,mid,from,to,v);
	if(to>mid)setmax(rc,mid+1,r,from,to,v);
	pushup(x);
}
int c[150005];
void Add(int p)
{
	while(p<=n)
	{
		c[p]++;
		p+=p^(p&(p-1));
	}
}
int Sum(int p)
{
	int ans=0;
	while(p)
	{
		ans+=c[p];
		p&=p-1;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	build(1,1,n);
	for(m=1;m<=n;m++)
	{
//		printf("setmax [%d,%d] %d\n",1,pos[m]-1,Sum(pos[m]));
		setmax(1,1,n,1,pos[m]-1,Sum(pos[m]));
//		for(int i=1;i<=9;i++)printf("%lld ",tree[i].sum);
//		printf("\n");
		Add(pos[m]);
//		printf("add [%d,%d] %d\n",pos[m],n,1);
		add(1,1,n,pos[m],n,1);
//		for(int i=1;i<=9;i++)pushdown(i),printf("%lld ",tree[i].sum);
//		printf("\n");
		update(1,1,n,pos[m]);
//		for(int i=1;i<=9;i++)pushdown(i),printf("%lld ",tree[i].sum);
//		printf("\n");
		ans[m]+=tree[1].sum;
	}
	memset(c,0,sizeof(c));
	for(int i=1;i*2<=n;i++)swap(a[i],a[n-i+1]);
	for(int i=1;i<=n;i++)pos[a[i]]=i;
	build(1,1,n);
	for(m=1;m<=n;m++)
	{
		setmax(1,1,n,1,pos[m]-1,Sum(pos[m]));
		Add(pos[m]);
		add(1,1,n,pos[m],n,1);
		update(1,1,n,pos[m]);
		ans[m]-=tree[1].num*m-tree[1].sum;
	}
	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
	return 0;
}