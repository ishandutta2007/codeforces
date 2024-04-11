#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Query
{
	int k;
	int p;
	int id;
}q[200005];
struct Data
{
	int v;
	int p;
}a[200005];
int n,m,ans[200005],sum[800005],v[200005];
bool cmp1(Data a,Data b)
{
	return a.v>b.v||(a.v==b.v&&a.p<b.p);
}
bool cmp2(Query x,Query y)
{
	return x.k<y.k;
}
void pushup(int o)
{
	sum[o]=sum[lson]+sum[rson];
}
void update(int o,int l,int r,int p)
{
	sum[o]++;
	if(l==r)return;
	if(p<=mid)update(lson,l,mid,p);
	else update(rson,mid+1,r,p);
}
int query(int o,int l,int r,int x)
{
	if(l==r)return v[l];
	if(x<=sum[lson])return query(lson,l,mid,x);
	else return query(rson,mid+1,r,x-sum[lson]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		a[i].v=v[i];
		a[i].p=i;
	}
	sort(a+1,a+n+1,cmp1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].k,&q[i].p);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp2);
	int now=0;
	for(int i=1;i<=m;i++)
	{
		while(now<q[i].k)
		{
			now++;
			update(1,1,n,a[now].p);
		}
		ans[q[i].id]=query(1,1,n,q[i].p);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}