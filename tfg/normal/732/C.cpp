#include <iostream>
#include <algorithm>

long long int a,b,c;

int main()
{
	std::cin >> a >> b >> c;
	long long int max=std::max(std::max(a,b),c);
	long long int ans=((long long int)2e18);
	if(max==a && max==b && max==c)
		ans=0;
	else if(max==a && max!=b && max!=c)
		ans=(a-b-1)+(a-c-1);
	else if(max!=a && max==b && max!=c)
		ans=(b-a-1)+(b-c-1);
	else if(max!=a && max!=b && max==c)
		ans=(c-b-1)+(c-a-1);
	else if(max==a && max==b)
		ans=a-c-1;
	else if(max==a && max==c)
		ans=c-b-1;
	else //if(max==b && max==c)
		ans=c-a-1;
	std::cout << ans << std::endl;
}