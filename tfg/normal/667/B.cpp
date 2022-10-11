#include <iostream>
#include <algorithm>

typedef long long int ll;

ll a[100100];
ll sum=0;

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		std::cin >> a[i];
		sum+=a[i];
		a[i]=-a[i];
	}
	std::sort(a,a+n);
	a[0]=-a[0];
	std::cout << 2*a[0]-sum+1 << '\n';
}