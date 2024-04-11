#include <iostream>
#include <algorithm>

int n, a[1010];

int main()
{
	std::cin >> n;
	int max=0;
	for(int i=1;i<=n;i++)
	{
		std::cin >> a[i];
		max=std::max(a[i], max);
	}
	long long int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=max-a[i];
	}
	std::cout << ans << '\n';
}