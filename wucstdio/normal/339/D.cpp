#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
int n,m,a[500005],tree[500005];
bool flag[500005];
void build(int o,int l,int r,bool f)
{
	flag[o]=f;
	if(l==r)
	{
		tree[o]=a[l];
		return;
	}
	build(lson,l,mid,!f);
	build(rson,mid+1,r,!f);
	if(f)tree[o]=tree[lson]|tree[rson];
	else tree[o]=tree[lson]^tree[rson];
}
void set(int o,int l,int r,int p,int v)
{
	if(l==r)
	{
		tree[o]=v;
		return;
	}
	if(p<=mid)set(lson,l,mid,p,v);
	else set(rson,mid+1,r,p,v);
	if(flag[o])tree[o]=tree[lson]|tree[rson];
	else tree[o]=tree[lson]^tree[rson];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(1<<n);i++)
	  scanf("%d",&a[i]);
	build(1,1,(1<<n),n&1);
//	for(int i=1;i<(1<<n+1);i++)
//	{
//		if(flag[i]!=flag[i-1])printf("\n");
//		printf("%d ",tree[i]);
//	}
//	printf("\n");
	for(int o=1;o<=m;o++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		set(1,1,(1<<n),x,y);
		a[x]=y;
		printf("%d\n",tree[1]);
//	for(int i=1;i<(1<<n+1);i++)
//	{
//		if(flag[i]!=flag[i-1])printf("\n");
//		printf("%d ",tree[i]);
//	}
//	printf("\n");
	}
}