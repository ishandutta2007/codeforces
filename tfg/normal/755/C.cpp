#include <iostream>

int p[100100];

int main()
{
	int n;
	std::cin >> n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int temp;
		std::cin >> temp;
		if(temp==i)
			ans++;
		else
			p[temp]++;
	}
	int other=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i])
			other++;
	}
	ans+=other/2;
	std::cout << ans << '\n';
}