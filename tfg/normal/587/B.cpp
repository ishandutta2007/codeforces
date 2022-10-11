#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

const ll MOD = ll(1e9) + 7;

ll comb(ll x){return x % MOD;}

ll dp2(int on, int got);

std::vector<std::vector<ll> > memo;
std::vector<ll> freq;
ll dp(int on, int got)
{
	if(got == 0)
	{
		if(on == 0)
			return 1;
		else
			return 0;
	}
	ll &ans = memo[on][got];
	if(ans != -1)
		return ans;
	ans = freq[on] * dp2(on, got - 1) % MOD;
	//std::cout << "on dp(" << on << ", " << got << ") returning " << ans << '\n';
	return ans;
}

std::vector<std::vector<ll> > sum;
ll dp2(int on, int got)
{
	if(on < 0)
		return 0;
	ll &ans = sum[on][got];
	if(ans != -1)
		return ans;
	ans = (dp(on, got) + dp2(on - 1, got)) % MOD;
	return ans;
}



int n, k;
ll l;

int main()
{
	while(std::cin >> n >> l >> k)
	{
		//std::cout << "new case\n";
		std::vector<ll> nums;
		std::map<ll, int> wtf;
		std::vector<ll> a(n, 0);
		
		for(int i = 0; i < n; i++)
		{
			scanf("%lli", &a[i]);
			if(wtf[a[i]] == 0)
				nums.push_back(a[i]);
			wtf[a[i]]++;
		}
		std::sort(nums.begin(), nums.end());
		freq = std::vector<ll>(nums.size() + 3, 0);
		for(int i = 0; i < nums.size(); i++)
		{
			freq[i] = wtf[nums[i]];
			wtf[nums[i]] = i;
		}
		sum = memo = std::vector<std::vector<ll> >(nums.size() + 3, std::vector<ll>(k + 3, -1));
		ll ans = 0;
		ll groups = l / n;
		ll missing = l - groups * n;
		for(int i = 1; i <= k && i <= groups; i++)
		{
			ans = (ans + comb(groups - i + 1) * dp2(nums.size() - 1, i)) % MOD;
			//std::cout << "for size " << i << ", adding " << comb(groups - i + 1) << " * " << dp2(nums.size() - 1, i) << '\n';
		}
		//std::cout << "first phase got " << ans << '\n';
		//std::cout << "missing = " << missing << '\n';
		for(int on = 0; on < missing; on++)
		{
			for(int i = 0; i < k && i <= groups; i++)
			{
				//std::cout << "rest of " << a[on] << "\n";
				int pos = wtf[a[on]];
				//std::cout << "on pos " << pos << '\n';
				ans = (ans + dp2(pos, i)) % MOD;
			}
		}
		std::cout << ans << '\n';
	}
}