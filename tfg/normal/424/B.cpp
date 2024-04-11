#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>

typedef long long int ll;
typedef std::pair<ll, ll> ii;
typedef std::pair<ii, ll> i3;

i3 a[10100];

bool cmp(ii a, ii b)
{
	return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
}

bool cmp2(i3 a, i3 b)
{
	return cmp(a.first, b.first);
}

int main()
{
	int n, s;
	std::cin >> n >> s;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i].first.first >> a[i].first.second >> a[i].second;
	}
	std::sort(a, a + n, cmp2);
	for(int i = 0; i < n; i++)
	{
		s += a[i].second;
		if(s >= 1e6)
		{
			std::cout << std::fixed << std::setprecision(10) << sqrt(a[i].first.first * a[i].first.first + a[i].first.second * a[i].first.second) << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";
}