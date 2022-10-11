#include <iostream>
#include <algorithm>

const int ms=1010;

int n;
int a[ms];
int freq[ms];

int main()
{
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		std::cin >> a[i];
		freq[a[i]]++;
	}
	int ans=0;
	while(n)
	{
		int got=0;
		for(int i=0;i<ms;i++)
		{
			if(freq[i])
			{
				freq[i]--;
				got++;
			}
		}
		ans+=got-1;
		n-=got;
	}

	std::cout << ans << '\n';
}