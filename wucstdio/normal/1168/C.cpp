#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
int n,m,a[300005];
struct Tree
{
	int res[19];
}tree[1200005];
void pushup(int o)
{
	for(int i=0;i<19;i++)
	{
		tree[o].res[i]=tree[lson].res[i];
		int v=tree[lson].res[i];
		for(int j=0;j<19;j++)
		  if((1<<j)&v)tree[o].res[i]|=tree[rson].res[j];
		tree[o].res[i]|=tree[rson].res[i];
	}
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<19;i++)
		  if((1<<i)&a[l])tree[o].res[i]=a[l];
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
}
int val;
bool ask(int o,int l,int r,int from,int to,int y)
{
	if(val&y)return 1;
	if(l>=from&&r<=to)
	{
		int x=0;
		for(int i=0;i<19;i++)
		  if((1<<i)&val)x|=tree[o].res[i];
		val|=x;
		return val&y;
	}
	bool f=0;
	if(from<=mid)f|=ask(lson,l,mid,from,to,y);
	if(f)return 1;
	if(to>mid)f|=ask(rson,mid+1,r,from,to,y);
	return f;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		val=a[x];
		if(ask(1,1,n,x+1,y-1,a[y]))printf("Shi\n");
		else printf("Fou\n");
	}
	return 0;
}