#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n,p[200005],x,y;
ll a,b,k,d;
bool cmp(int a,int b)
{
	return a>b;
}
bool check(int n)
{
	ll n1=n/d,n2,n3;
	if(x>y)n2=n/a-n1,n3=n/b-n1;
	else n2=n/b-n1,n3=n/a-n1;
	ll tot=0;
	for(int i=1;i<=n1;i++)tot+=p[i]/100*(x+y);
	for(int i=1;i<=n2;i++)tot+=p[i+n1]/100*max(x,y);
	for(int i=1;i<=n3;i++)tot+=p[i+n1+n2]/100*min(x,y);
	return tot>=k;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		sort(p+1,p+n+1,cmp);
		scanf("%d%lld%d%lld%lld",&x,&a,&y,&b,&k);
		d=__gcd(a,b);
		d=a*b/d;
		int l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		if(l<=n)printf("%d\n",l);
		else printf("-1\n");
	}
	return 0;
}