#include <iostream>

int price, d;

int main()
{
	std::cin >> price >> d;
	int l=price%10;
	int ans=0;
	while(l!=d && l!=0)
	{
		ans++;
		l=(l+price%10)%10;
	}
	std::cout << ans+1 << std::endl;
}