#include <iostream>
#include <algorithm>

typedef long long ll;

const int ms = 100100;

int n;
ll S;
ll a[ms];
ll b[ms];

ll can(int k)
{
	ll cost = 0;
	for(int i = 0; i < n; i++)
		b[i] = a[i] + (ll) k * (i + 1);
	std::sort(b, b + n);
	for(int i = 0; i < k; i++)
		cost += b[i]; //std::cout << b[i] << ' ';
	//std::cout << '\n';
	if(cost > S)
		return -1;
	else
		return cost;
}

int main()
{
	std::cin >> n >> S;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	int l = 0, r = n;
	while(l != r)
	{
		int mid = (l + r + 1) / 2;
		if(can(mid) >= 0)
			l = mid;
		else
			r = mid - 1;
	}
	std::cout << l << ' ' << (l == 0? 0 : can(l)) << '\n';
}