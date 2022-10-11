#include <iostream>

int n, a[1010], b[1010];

int fa[1010], fb[1010];

int main()
{
	std::cin >> n;
	for(int i=0;i<n;i++)
		std::cin >> a[i];
	for(int i=0;i<n;i++)
		std::cin >> b[i];
	for(int i=0;i<n;i++)
	{
		fa[a[i]]++;
		fb[b[i]]++;
	}
	int ans=0;
	for(int i=0;i<=5;i++)
	{
		if((fa[i]+fb[i])%2==1)
		{
			std::cout << "-1\n";
			return 0;
		}
		ans+=std::max(fa[i],fb[i])-(fa[i]+fb[i])/2;
	}
	std::cout << ans/2 << '\n';
}