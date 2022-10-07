#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
#define ll long long
using namespace std;
struct People
{
	ll a,b;
	ll cha;
	int p;
}a[300005];
ll n,m,rnk[300005],ans,add[300005];
bool cmp(People a,People b)
{
	return a.cha<b.cha;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&a[i].a,&a[i].b);
		a[i].cha=a[i].a-a[i].b;
		a[i].p=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	  rnk[a[i].p]=i;
	for(int i=1;i<=n;i++)
	{
		add[1]+=a[i].b;
		add[i]-=a[i].b;
		add[i+1]+=a[i].a;
		add[i]+=a[i].a*(n-i)+a[i].b*(i-1);
		add[i+1]-=a[i].a*(n-i)+a[i].b*(i-1);
	}
	for(int i=1;i<=n;i++)
	  add[i]+=add[i-1];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u=rnk[u];
		v=rnk[v];
		ll va;
		if(a[u].a+a[v].b>a[u].b+a[v].a)va=a[u].b+a[v].a;
		else va=a[u].a+a[v].b;
		add[u]-=va;
		add[v]-=va;
	}
	for(int i=1;i<=n;i++)
	  printf("%I64d ",add[rnk[i]]);
	printf("\n");
	return 0;
}