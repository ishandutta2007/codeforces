#include <iostream>
#include <algorithm>

int n;
int a, b;

int main()
{
	std::cin >> n;
	a=1;
	b=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a=i;
			b=n/i;
		}
	}
	std::cout << a << ' ' << b << '\n';
}