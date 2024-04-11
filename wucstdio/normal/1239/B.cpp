#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Tree
{
	int minn;
	int num;
	int pre,suf;
	int ans;
	int l,r;
	int ll,rr;
}tree[1200005];
int n,a[300005],minv;
char s[300005];
void pushup(int o)
{
	tree[o].ans=0;
	if(tree[lson].ans>tree[o].ans)
	{
		tree[o].l=tree[lson].l,tree[o].r=tree[lson].r;
		tree[o].ans=tree[lson].ans;
	}
	if(tree[rson].ans>tree[o].ans)
	{
		tree[o].l=tree[rson].l,tree[o].r=tree[rson].r;
		tree[o].ans=tree[rson].ans;
	}
	if(tree[lson].suf+tree[rson].pre>tree[o].ans)
	{
		tree[o].ans=tree[lson].suf+tree[rson].pre;
		tree[o].l=tree[lson].ll,tree[o].r=tree[rson].rr;
	}
	tree[o].minn=min(tree[lson].minn,tree[rson].minn);
	tree[o].num=tree[lson].num+tree[rson].num;
	tree[o].pre=tree[lson].pre;
	tree[o].rr=tree[lson].rr;
	if(tree[lson].minn>=minv+2&&tree[lson].num+tree[rson].pre>tree[o].pre)
	{
		tree[o].pre=tree[lson].num+tree[rson].pre;
		tree[o].rr=tree[rson].rr;
	}
	tree[o].suf=tree[rson].suf;
	tree[o].ll=tree[rson].ll;
	if(tree[rson].minn>=minv+2&&tree[rson].num+tree[lson].suf>tree[o].suf)
	{
		tree[o].suf=tree[rson].num+tree[lson].suf;
		tree[o].ll=tree[lson].ll;
	}
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].minn=a[l];
		if(a[l]==minv+2)tree[o].num=1;
		else tree[o].num=0;
		if(a[l]==minv+2&&a[l]>a[l-1])tree[o].suf=1,tree[o].ll=l;
		else tree[o].suf=-10000000;
		if(a[l]==minv+2&&a[l]>a[l+1])tree[o].pre=1,tree[o].rr=l+1;
		else tree[o].pre=-10000000;
		if(a[l]==minv+2&&a[l]>a[l+1]&&a[l]>a[l-1])tree[o].ans=1,tree[o].l=l,tree[o].r=l+1;
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
//	printf("[%d,%d]:ans=%d,ansl=%d,ansr=%d,pre=%d,suf=%d,ll=%d,rr=%d\n",l,r,tree[o].ans,tree[o].l,tree[o].r,tree[o].pre,tree[o].suf,tree[o].ll,tree[o].rr);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
		minv=min(minv,a[i]);
	}
	if(a[n]!=0)
	{
		printf("0\n1 1\n");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
//		printf("%d ",a[i]);
		if(a[i]==minv)
		  ans++;
	}
//	printf("\n");
	build(1,1,n);
	int maxx=tree[1].ans+ans;
	int ansl=tree[1].l,ansr=tree[1].r;
	minv--;
	build(1,1,n);
	if(tree[1].ans>maxx)
	{
		maxx=max(maxx,tree[1].ans);
		ansl=tree[1].l,ansr=tree[1].r;
	}
	ans=maxx;
	int l=n+1,r=0;
	minv++;
	for(int i=1;i<=n;i++)
	  if(a[i]==minv)l=min(l,i),r=i;
	for(int i=l;i<=r;i++)a[i]+=2;
	maxx=0;
	minv=100;
	for(int i=1;i<=n;i++)minv=min(minv,a[i]);
	for(int i=1;i<=n;i++)
	  if(a[i]==minv)maxx++;
	if(maxx>ans)
	{
		ans=maxx;
		ansl=l,ansr=r+1;
	}
	for(int i=l;i<=r;i++)a[i]-=2;
	for(int i=1;i<=n;i++)minv=min(minv,a[i]);
	minv++;
	l=n+1,r=0;
	for(int i=1;i<=n;i++)
	  if(a[i]<=minv)l=min(l,i),r=i;
	for(int i=l;i<=r;i++)a[i]+=2;
	maxx=0;
	minv=100;
	for(int i=1;i<=n;i++)minv=min(minv,a[i]);
	for(int i=1;i<=n;i++)
	  if(a[i]==minv)maxx++;
	if(maxx>ans)
	{
		ans=maxx;
		ansl=l,ansr=r+1;
	}
	for(int i=l;i<=r;i++)a[i]-=2;
	printf("%d\n",ans);
	if(ansl==0&&ansr==0)ansl=ansr=1;
	printf("%d %d\n",ansl,ansr);
	return 0;
}