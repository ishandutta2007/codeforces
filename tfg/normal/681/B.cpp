#include <iostream>

typedef long long ll;

ll a[] = {1234567, 123456, 1234};

int main()
{
	
	ll n;
	while(std::cin >> n)
	{
		bool ans = false;
		for(ll i = 0; i * a[0] <= n; i++)
		{
			ll cur = i * a[0];
			for(ll j = 0; cur + j * a[1] <= n; j++)
			{
				ll dude = cur + j * a[1];
				if((n - dude) % a[2] == 0)
					ans = true;
			}
		}
		if(ans)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}