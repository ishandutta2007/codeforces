#include <iostream>
#include <cstdio>

typedef long long ll;

ll times[2][2];

int main()
{
	times[0][0]=times[1][0]=ll(1e10);
	times[0][1]=times[1][1]=-ll(1e10);
	for(int i=0;i<2;i++)
	{
		int n;
		std::cin >> n;
		while(n--)
		{
			ll a, b;
			//std::cin >> a >> b;
			scanf("%lli %lli", &a, &b);
			times[i][0]=std::min(times[i][0], b);
			times[i][1]=std::max(times[i][1], a);
		}
		//std::cout << times[i][0] << ' ' << times[i][1] << '\n';
	}
	
	ll ans=std::max(times[1][1]-times[0][0], times[0][1]-times[1][0]);
	ans=std::max(ans, 0LL);
	std::cout << ans << '\n';
}