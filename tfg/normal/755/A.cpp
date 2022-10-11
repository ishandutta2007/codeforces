#include <iostream>

bool prime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	std::cin >> n;
	if(n%2==1)
		std::cout << "3\n";
	else
	{
		int on=1;
		while(prime(on*n+1))
			on++;
		std::cout << on << '\n';
	}
}