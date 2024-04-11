#include <iostream>
#include <algorithm>

typedef long long int ll;

ll k2,k3,k5,k6;

int main()
{
	std::cin >> k2 >> k3 >> k5 >> k6;
	ll first=std::min(k2,std::min(k5,k6));
	k2-=first;
	ll second=std::min(k2,k3);
	std::cout << first*256LL + second*32 << '\n';
}