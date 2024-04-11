#include <iostream>

int n, x;

int a[100100];
int freq[100100];

int main()
{
	std::cin >> n >> x;
	for(int i=0;i<n;i++)
	{
		std::cin >> a[i];
		freq[a[i]]++;
	}
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		int needed=a[i]^x;
		if(needed>100000)
			continue;
		int pairs=freq[needed];
		if(needed==a[i])
			pairs--;
		ans+=pairs;
	}
	std::cout << ans/2 << '\n';
}