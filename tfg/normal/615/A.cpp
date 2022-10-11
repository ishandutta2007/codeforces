#include <iostream>

int n, m;
int freq[1010];

int main()
{
	std::cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		int temp;
		std::cin >> temp;
		while(temp--)
		{
			int lul;
			std::cin >> lul;
			freq[lul]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!freq[i])
		{
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
}