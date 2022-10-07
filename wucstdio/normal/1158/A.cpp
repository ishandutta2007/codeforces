#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m;
ll a[100005],b[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%I64d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(a[n]>b[1])
	{
		printf("-1\n");
		return 0;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=a[i];
	ans*=m;
	if(a[n]==b[1])
	{
		for(int i=1;i<=m;i++)
		  ans+=b[i]-a[n];
	}
	else
	{
		for(int i=1;i<=m;i++)
		  ans+=b[i]-a[n];
		ans+=a[n]-a[n-1];
	}
	printf("%I64d\n",ans);
	return 0;
}