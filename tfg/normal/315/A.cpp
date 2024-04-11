#include <iostream>

const int ms=1100;

int par[ms], b[ms];
int can_open[ms];

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		std::cin >> par[i] >> b[i];
		can_open[b[i]]++;
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans+=(can_open[par[i]] > 1) || (can_open[par[i]] && b[i]!=par[i]);
	std::cout << n-ans << '\n';
}