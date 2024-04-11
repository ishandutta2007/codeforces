#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

typedef long long ll;

const int mb = 11;
const int ms = 68;

ll memo[mb][ms][mb];
ll dp(int base, int on, int mask)
{
	if(mask < 0 || mask > base)
		return 0;
	if(on == 0)
		return mask == 0 ? 1 : 0;
	ll &ans = memo[base][on][mask];
	if(ans != -1)
		return ans;
	ans = mask * dp(base, on - 1, mask - 1) + (base - mask) * dp(base, on - 1, mask + 1);
	//std::cout << "on (" << base << ", " << on << ", " << mask  << ") = " << ans << "\n";
	return ans;
}

ll solve(ll x, int base)
{
	//std::cout << "solving (" << x << ", " << base << ")\n";
	if(x < base)
	{
		//std::cout << "got " << 0 << '\n';
		return 0;
	}
	std::vector<int> nums;
	while(x)
	{
		nums.push_back(x % base);
		x /= base;
	}
	std::reverse(nums.begin(), nums.end());
	ll ans = 0;
	//std::cout << "ans = " << ans << '\n';
	int mask = 0;
	int odd = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		//std::cout << nums[i] << ' ';
		if(i)
			ans += (base - 1) * dp(base, nums.size() - i - 1, 1);
		for(int j = (i == 0 ? 1 : 0); j < nums[i]; j++)
		{
			if(mask & (1 << j))
				ans += dp(base, nums.size() - i - 1, odd - 1);
			else
				ans += dp(base, nums.size() - i - 1, odd + 1);
		}
		if(mask & (1 << nums[i]))
			odd--;
		else
			odd++;
		mask ^= (1 << nums[i]); 
	}
	//std::cout << '\n';
	if(mask == 0)
		ans++;
	//std::cout << "got " << ans << '\n';
	return ans;
}

int main()
{
	memset(memo, -1, sizeof memo);
	int q;
	std::cin >> q;
	while(q--)
	{
		ll b, l, r;
		//std::cin >> b >> l >> r;
		scanf("%lli %lli %lli", &b, &l, &r);
		printf("%lli\n", solve(r, b) - solve(l - 1, b));
	}
}