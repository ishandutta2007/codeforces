#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson o<<1
#define rson o<<1|1
#define mid ((l+r)>>1)
using namespace std;
struct Tree
{
	int pre,suf,num;
	ll tot;
	bool flag;
}tree[800005];
struct Point
{
	int x,y;
}p[200005];
int n,m,sa[200005];
ll ans;
bool cmp(int a,int b)
{
	return p[a].y<p[b].y;
}
bool cmp2(Point a,Point b)
{
	return a.x<b.x;
}
void pushup(int o)
{
	tree[o].num=tree[lson].num+tree[rson].num;
	tree[o].pre=tree[lson].pre==tree[lson].num?tree[lson].num+tree[rson].pre:tree[lson].pre;
	tree[o].suf=tree[rson].suf==tree[rson].num?tree[rson].num+tree[lson].suf:tree[rson].suf;
	tree[o].tot=tree[lson].tot+tree[rson].tot+1ll*tree[lson].suf*tree[rson].pre;
}
void pushdown(int o)
{
	if(tree[o].flag)
	{
		tree[lson].flag=1;
		tree[lson].tot=1ll*tree[lson].num*(tree[lson].num+1)/2;
		tree[lson].pre=tree[lson].suf=tree[lson].num;
		tree[rson].flag=1;
		tree[rson].tot=1ll*tree[rson].num*(tree[rson].num+1)/2;
		tree[rson].pre=tree[rson].suf=tree[rson].num;
		tree[o].flag=0;
	}
}
void add(int o,int l,int r,int p)
{
	if(l==r)
	{
		tree[o].num=1;
		tree[o].tot=tree[o].pre=tree[o].suf=0;
		return;
	}
	pushdown(o);
	if(p<=mid)add(lson,l,mid,p);
	else add(rson,mid+1,r,p);
	pushup(o);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		swap(p[i].x,p[i].y);
		p[i].x=1000000001-p[i].x;
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp);
	int pre=0;m=0;
	for(int i=1;i<=n;i++)
	{
		if(p[sa[i]].y!=pre)m++;
		pre=p[sa[i]].y;
		p[sa[i]].y=m;
	}
	sort(p+1,p+n+1,cmp2);
	for(int i=1;i<=n;)
	{
		tree[1].flag=1;
		tree[1].tot=1ll*tree[1].num*(tree[1].num+1)/2;
		tree[1].pre=tree[1].suf=tree[1].num;
		int j=i;
		while(p[j].x==p[i].x)add(1,1,m,p[j].y),j++;
		ans+=1ll*tree[1].num*(tree[1].num+1)/2;
		ans-=tree[1].tot;
		i=j;
	}
	printf("%lld\n",ans);
	return 0;
}