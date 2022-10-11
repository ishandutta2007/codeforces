#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>

typedef long long int ll;
typedef std::pair<int, int> ii;

int n;

ll a[300300];
ll sum[300300];

ll memo[300300];

int main()
{
	sum[0]=0;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lli",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	memo[n]=0;
	ll s_max=sum[n];
	for(int i=n-1;i>=1;i--)
	{
		memo[i]=s_max;
		//std::cout << "returning " << memo[i] << " on " << i << std::endl;
		s_max=std::max(sum[i]-memo[i],s_max);
	}
	std::cout << memo[1] << std::endl;

}