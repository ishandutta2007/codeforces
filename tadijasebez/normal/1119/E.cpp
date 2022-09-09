#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,cnt=0,x;
	scanf("%i",&n);
	ll ans=0;
	while(n--)
	{
		scanf("%i",&x);
		while(cnt && x>=2)
		{
			ans++;
			cnt--;
			x-=2;
		}
		ans+=x/3;
		cnt+=x%3;
	}
	printf("%lld\n",ans);
	return 0;
}