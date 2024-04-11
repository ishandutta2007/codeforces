#include<cstdio>
#include<algorithm>
#include<cstring>
#define lc x<<1
#define rc x<<1|1
#define mid ((l+r)>>1)
#define ll long long
using namespace std;
struct Tree
{
	ll add;
	ll minn;
}tree[4000005];
struct Data
{
	ll cost;
	int val;
}a[200005],b[200005];
struct Monster
{
	int x,y;
	ll c;
}c[200005];
int n,m,p;
void pushup(int x)
{
	tree[x].minn=min(tree[lc].minn,tree[rc].minn);
}
void pushdown(int x)
{
	if(tree[x].add)
	{
		tree[lc].add+=tree[x].add;
		tree[rc].add+=tree[x].add;
		tree[lc].minn+=tree[x].add;
		tree[rc].minn+=tree[x].add;
		tree[x].add=0;
	}
}
void update(int x,int l,int r,int from,int to,ll v)
{
	if(from>to)return;
	if(l>=from&&r<=to)
	{
		tree[x].add+=v;
		tree[x].minn+=v;
		return;
	}
	pushdown(x);
	if(from<=mid)update(lc,l,mid,from,to,v);
	if(to>mid)update(rc,mid+1,r,from,to,v);
	pushup(x);
}
bool cmp1(Data a,Data b)
{
	return a.val<b.val||(a.val==b.val&&a.cost>b.cost);
}
bool cmp2(Monster x,Monster y)
{
	return x.x<y.x;
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%d%lld",&a[i].val,&a[i].cost);
	for(int i=1;i<=m;i++)scanf("%d%lld",&b[i].val,&b[i].cost);
	for(int i=1;i<=p;i++)scanf("%d%d%lld",&c[i].x,&c[i].y,&c[i].c);
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+m+1,cmp1);
	sort(c+1,c+p+1,cmp2);
	b[++m].val=1000000,b[m].cost=10000000000;
	for(int i=m;i>=1;i--)
	{
		if(i!=m&&b[i].cost>b[i+1].cost)b[i].cost=b[i+1].cost;
		update(1,1,1000000,b[i-1].val+1,b[i].val,b[i].cost);
//		printf("[%d,%d],%lld\n",b[i-1].val+1,b[i].val,b[i].cost);
	}
	int now=1;
	ll ans=1e18;
	for(int i=1;i<=n;i++)
	{
		while(now<=p&&c[now].x<a[i].val)
		{
			update(1,1,1000000,c[now].y+1,1000000,-c[now].c);
			now++;
		}
		ans=min(ans,tree[1].minn+a[i].cost);
	}
	printf("%lld\n",-ans);
	return 0;
}