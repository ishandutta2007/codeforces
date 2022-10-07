#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Tree
{
	int val;
	int num;
	int len1,len2,m1,m2;
	int add,tagmax,tagmin;
	int bmin,bmax;
}tree[1200005];
int n,a[300005];
ll ans;
void pushup(int o)
{
	tree[o].val=min(tree[lson].val,tree[rson].val);
	tree[o].num=0;
	if(tree[lson].val==tree[o].val)tree[o].num+=tree[lson].num;
	if(tree[rson].val==tree[o].val)tree[o].num+=tree[rson].num;
	tree[o].len1=min(tree[lson].len1,tree[rson].len1);
	tree[o].m1=0;
	if(tree[lson].len1==tree[o].len1)tree[o].m1+=tree[lson].m1;
	if(tree[rson].len1==tree[o].len1)tree[o].m1+=tree[rson].m1;
	tree[o].len2=max(tree[lson].len2,tree[rson].len2);
	tree[o].m2=0;
	if(tree[lson].len2==tree[o].len2)tree[o].m2+=tree[lson].m2;
	if(tree[rson].len2==tree[o].len2)tree[o].m2+=tree[rson].m2;
	tree[o].bmax=max(tree[lson].bmax,tree[rson].bmax);
	tree[o].bmin=min(tree[lson].bmin,tree[rson].bmin);
}
void pushdown(int o)
{
	if(tree[o].add)
	{
		tree[lson].add+=tree[o].add;
		tree[rson].add+=tree[o].add;
		tree[lson].bmin+=tree[o].add;
		tree[rson].bmin+=tree[o].add;
		tree[lson].bmax+=tree[o].add;
		tree[rson].bmax+=tree[o].add;
		tree[lson].val-=tree[o].add;
		tree[rson].val-=tree[o].add;
		tree[lson].len1-=tree[o].add;
		tree[rson].len1-=tree[o].add;
		tree[lson].len2+=tree[o].add;
		tree[rson].len2+=tree[o].add;
		tree[o].add=0;
	}
	if(tree[o].tagmax)
	{
		tree[lson].tagmax=tree[o].tagmax;
		tree[rson].tagmax=tree[o].tagmax;
		tree[lson].len1=tree[o].tagmax-tree[lson].bmax;
		tree[rson].len1=tree[o].tagmax-tree[rson].bmax;
		tree[lson].m1=1;
		tree[rson].m1=1;
		tree[lson].val=tree[o].tagmax-tree[lson].len2;
		tree[rson].val=tree[o].tagmax-tree[rson].len2;
		tree[lson].num=tree[lson].m2;
		tree[rson].num=tree[rson].m2;
		tree[o].tagmax=0;
	}
	if(tree[o].tagmin)
	{
		tree[lson].tagmin=tree[o].tagmin;
		tree[rson].tagmin=tree[o].tagmin;
		tree[lson].len2=tree[o].tagmin+tree[lson].bmax;
		tree[rson].len2=tree[o].tagmin+tree[rson].bmax;
		tree[lson].m2=1;
		tree[rson].m2=1;
		tree[lson].val=-tree[o].tagmin+tree[lson].len1;
		tree[rson].val=-tree[o].tagmin+tree[rson].len1;
		tree[lson].num=tree[lson].m1;
		tree[rson].num=tree[rson].m1;
		tree[o].tagmin=0;
	}
}
void add(int o,int l,int r,int from,int to,int v)
{
	if(l>=from&&r<=to)
	{
		tree[o].add+=v;
		tree[o].bmin+=v;
		tree[o].bmax+=v;
		tree[o].val-=v;
		tree[o].len1-=v;
		tree[o].len2+=v;
		return;
	}
	pushdown(o);
	if(from<=mid)add(lson,l,mid,from,to,v);
	if(to>mid)add(rson,mid+1,r,from,to,v);
	pushup(o);
}
void set_max(int o,int l,int r,int from,int to,int v)
{
	if(l>=from&&r<=to)
	{
		tree[o].tagmax=v;
		tree[o].len1=v-tree[o].bmax;
		tree[o].m1=1;
		tree[o].val=v-tree[o].len2;
		tree[o].num=tree[o].m2;
		return;
	}
	pushdown(o);
	if(from<=mid)set_max(lson,l,mid,from,to,v);
	if(to>mid)set_max(rson,mid+1,r,from,to,v);
	pushup(o);
}
void set_min(int o,int l,int r,int from,int to,int v)
{
	if(l>=from&&r<=to)
	{
		tree[o].tagmin=v;
		tree[o].len2=v+tree[o].bmax;
		tree[o].m2=1;
		tree[o].val=-v+tree[o].len1;
		tree[o].num=tree[o].m1;
		return;
	}
	pushdown(o);
	if(from<=mid)set_min(lson,l,mid,from,to,v);
	if(to>mid)set_min(rson,mid+1,r,from,to,v);
	pushup(o);
}
int ask(int o,int l,int r,int from,int to)
{
	if(l>=from&&r<=to)return tree[o].val==0?tree[o].num:0;
	int ans=0;
	if(from<=mid)ans+=ask(lson,l,mid,from,to);
	if(to>mid)ans+=ask(rson,mid+1,r,from,to);
	return ans;
}
int maxv[300005],top1;
int minv[300005],top2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]=y;
	}
	for(int i=1;i<=n;i++)
	{
		while(top1&&a[maxv[top1]]<a[i])top1--;
		maxv[++top1]=i;
		set_max(1,1,n,maxv[top1-1]+1,i,a[i]);
		while(top2&&a[minv[top2]]>a[i])top2--;
		minv[++top2]=i;
		set_min(1,1,n,minv[top2-1]+1,i,a[i]);
		ans+=ask(1,1,n,1,i);
		add(1,1,n,1,i,1);
	}
	printf("%lld\n",ans);
	return 0;
}