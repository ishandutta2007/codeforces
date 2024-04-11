#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int a[200200];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a, a + n);
	int war = n - 1 - (n - 1) / 2;
	//std::cout << "war is " << war << '\n';
	int ans = int(1e9) + 10;
	for(int i = 0; i + war < n; i++)
		ans = std::min(ans, a[i + war] - a[i]);
	std::cout << ans << '\n';
}