#include <iostream>
#include <algorithm>

int a[3030];

int main()
{
	int n;
	std::cin >> n;
	int ans = 0;
	for(int i=1;i<=n;i++)
		std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	for(int i=1;i<=n;i++)
	{
		if(a[i] <= a[i-1])
		{
			ans += a[i-1] + 1 - a[i];
			a[i] = a[i-1] + 1;
		}
	}
	std::cout << ans << '\n';
}