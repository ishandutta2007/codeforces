#include <iostream>

int main()
{
	long long k, n, w;
	std::cin >> k >> n >> w;
	for(long long i=1;i<=w;i++)
		n -= i*k;
	if(n<0)
		n = -n;
	else
		n = 0;
	std::cout << n << '\n';
}