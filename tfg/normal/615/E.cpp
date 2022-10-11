#include <iostream>
#include <cassert>

typedef long long ll;

ll combs(ll x)
{
	if(x<=0)
		return 0;
	return (x*(x+1))/2;
}

ll steps(ll x)
{
	return combs(x-2)+5*combs(x-1);
}

int main()
{
	ll n;
	//for(int i=1;i<10;i++)
	//	std::cout << steps(i) << '\n';
	while(std::cin >> n)
	{
		ll sum=0;
		ll x, y;
		x=y=0;
		ll on=1;
		/*while(sum+4*on+on-1<=n)
		{
			x++;
			y-=2;
			sum+=4*on+on-1;
			on++;
		}*/
		//std::cout << "on is " << on << '\n';
		//std::cout << "sum is " << sum << '\n';
		ll l, r;
		l=1;
		r=ll(1e9);
		while(l!=r)
		{
			ll mid=(l+r+1)/2;
			if(steps(mid)<=n)
				l=mid;
			else
				r=mid-1;
		}
		 on=l;
		 x=on-1;
		 y=-2*on+2;
		 sum=steps(on);
		//std::cout << "on is " << on << '\n';
		//std::cout << "sum is " << sum << '\n';
		if(n-sum<=on)
		{
			std::cout << x+n-sum << ' ' << y+2*(n-sum) << '\n';
			//return 0;
			continue;
		}
		x+=on;
		y+=2*on;
		sum+=on;
		if(n-sum<=on-1)
		{
			std::cout << x-(n-sum) << ' ' << y+2*(n-sum) << '\n';
			continue;
		}
		x-=on-1;
		y+=2*(on-1);
		sum+=on-1;
		if(n-sum<=on)
		{
			std::cout << x-2*(n-sum) << ' ' << y << '\n';
			//return 0;
			continue;
		}
		x-=2*on;
		sum+=on;
		if(n-sum<=on)
		{
			std::cout << x-(n-sum) << ' ' << y-2*(n-sum) << '\n';
			//return 0;
			continue;
		}
		x-=on;
		y-=2*on;
		sum+=on;
		if(n-sum<=on)
		{
			std::cout << x+(n-sum) << ' ' << y-2*(n-sum) << '\n';
			//return 0;
			continue;
		}
		x+=on;
		y-=2*on;
		sum+=on;
		if(n-sum<=on)
		{
			std::cout << x+2*(n-sum) << ' ' << y << '\n';
			continue;
		}
		std::cout << "wtf\n";
		assert(0);
	}
}