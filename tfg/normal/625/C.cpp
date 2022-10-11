#include <iostream>

int m[550][550];

int n, k;

int main()
{
	std::cin >> n >> k;
	int count=1;
	k--;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			m[i][j]=count++;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=count;
		for(int j=k;j<n;j++)
		{
			m[i][j]=count++;
		}
	}
	std::cout << ans << '\n';
	for(int i=0;i<n;i++)
	{
		std::cout << m[i][0];
		for(int j=1;j<n;j++)
			std::cout << ' ' << m[i][j];
		std::cout << '\n';
	}
}