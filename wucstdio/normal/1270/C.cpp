#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n;
ll a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll sum=0,x=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
			x^=a[i];
		}
		printf("2\n%lld %lld\n",x,sum+x);
	}
	return 0;
}