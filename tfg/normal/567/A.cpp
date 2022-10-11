#include <iostream>

int n;
int a[100100];

int main()
{
	std::cin >> n;
	for(int i=0;i<n;i++)
		std::cin >> a[i];
	std::cout << a[1]-a[0] << ' ' << a[n-1] - a[0] << '\n';
	for(int i=1;i<n-1;i++)
	{
		std::cout << std::min(a[i]-a[i-1], a[i+1]-a[i]) << ' ' << std::max(a[i]-a[0], a[n-1]-a[i]) << '\n';
	}
	std::cout << a[n-1]-a[n-2] << ' ' << a[n-1] - a[0] << '\n';
}