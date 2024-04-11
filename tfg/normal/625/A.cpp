#include <iostream>

typedef long long int ll;

ll n,a,b,c;

int main()
{
	std::cin >> n >> a >> b >> c;
	ll cost=b-c;
	ll ans=0;
	if(cost<a && b<=n)
	{
		ll count=(n-b)/cost;
		//if(n-cost*count>b)
			//count-=(b+cost*count-n+cost-1)/cost;

		n-=cost*count;
		while(n>=b)
		{
			count++;
			n-=cost;
		}
		ans+=count;
		//std::cout << "used " << count << " glasses\n";
	}
	ans+=n/a;
	std::cout << ans << std::endl;
}