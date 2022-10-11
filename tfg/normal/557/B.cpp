#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>

typedef long long int ll;

const int ms=200200;

int n;
ll a[ms];
ll w;

int main()
{
	std::cin >> n >> w;
	for(int i=0;i<2*n;i++)
		scanf("%lli",a+i);
	std::sort(a, a+2*n);
	ll man=std::min(2*a[0], a[n]);
	std::cout << std::fixed << std::setprecision(7);
	std::cout << std::min(n*(man/2.0+man), (double)w) << '\n';
}