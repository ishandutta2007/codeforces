#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

std::vector<ll> generate(ll x)
{
	std::vector<ll> ans;
	ll cur = 1;
	for(double wtf = 1; wtf < 1.1e18 ; wtf *= x, cur *= x)
		ans.push_back(cur);
	return ans;
}

int main()
{
	ll x, y, l, r;
	std::cin >> x >> y >> l >> r;
	std::vector<ll> a, b;
	a = generate(x);
	b = generate(y);
	ll ans = 0;
	std::set<ll> nums;
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
		{
			ll cur = a[i] + b[j];
			if(l <= cur && cur <= r)
			{
				//std::cout << "got " << a[i] << " + " << b[j] << "\n";
				nums.insert(cur);
			}
		}
	}
	nums.insert(r + 1);
	ll last = l - 1;
	for(std::set<ll>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		ans = std::max(ans, *it - last - 1);
		last = *it;
	}
	std::cout << ans << '\n';
}