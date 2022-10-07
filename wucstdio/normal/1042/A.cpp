#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,m,a[105],sum[105];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	  sum[i]=sum[i-1]+a[i];
	if(a[n]*n-sum[n]>=m)printf("%I64d ",a[n]);
	else printf("%I64d ",a[n]+(m-(a[n]*n-sum[n])-1)/n+1);
	printf("%I64d\n",a[n]+m);
	return 0;
}