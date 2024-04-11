#include <iostream>

int n;

int fexp(int x, int e)
{
	int ans=1;
	while(e)
	{
		if(e&1)
			ans=(ans*x)%10;
		x=(x*x)%10;
		e=e>>1;
	}
	return ans;
}

int main()
{
	std::cin >> n;
	std::cout << fexp(8,n) << '\n';
}