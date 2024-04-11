#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll a[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==1)
	{
		printf("1 1\n0\n1 1\n0\n1 1\n%lld\n",-a[1]);
		return 0;
	}
	printf("1 %d\n",n);
	printf("0 ");
	for(int i=2;i<=n;i++)
	{
		ll k=a[i]%(n-1);
		if(k<0)k+=n-1;
		printf("%lld ",1ll*n*(n-1-k));
		a[i]+=1ll*n*(n-1-k);
	}
	printf("\n");
	printf("1 1\n%lld\n",-a[1]);
	printf("2 %d\n",n);
	for(int i=2;i<=n;i++)printf("%lld ",-a[i]);
	printf("\n");
	return 0;
}