#include <iostream>

typedef long long ll;

int main()
{
	int ans=0;
	ll a, b;
	std::cin >> a >> b;
	while(a<=b)
	{
		ans++;
		a*=3;
		b*=2;
	}
	std::cout << ans << '\n';
}