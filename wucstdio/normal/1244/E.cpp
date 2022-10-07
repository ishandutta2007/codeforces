#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll a[100005],k;
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(1)
	{
		if(l==r)
		{
			printf("0\n");
			return 0;
		}
		if(l==r-1)
		{
			ll d=k/l;
			if(a[r]-a[l]<=d)
			{
				printf("0\n");
				return 0;
			}
			else
			{
				printf("%lld\n",a[r]-a[l]-d);
				return 0;
			}
		}
		ll d=k/l;
		if(d>=a[l+1]-a[l]+a[r]-a[r-1])
		{
			k-=l*(a[l+1]-a[l]+a[r]-a[r-1]);
			l++,r--;
		}
		else
		{
			printf("%lld\n",a[r]-a[l]-k/l);
			return 0;
		}
	}
	return 0;
}