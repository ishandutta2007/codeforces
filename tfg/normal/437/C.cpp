#include <iostream>
#include <algorithm>

typedef long long int ll;

const int ms=2020;

int n, m;
int a[ms];


int main()
{
	std::cin >> n >> m;
	for(int i=1;i<=n;i++)
		std::cin >> a[i];

	ll ans=0;
	for(int i=0;i<m;i++)
	{
		int t1, t2;
		std::cin >> t1 >> t2;
		ans+=std::min(a[t1], a[t2]);
	}
	std::cout << ans << '\n';
}