#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>

typedef long long int ll;

const int ms = 200200;

int n, m;
std::vector<int> divs[200200];
std::vector<int> primes[200200];

ll fexp(ll x, int e, ll mod)
{
	ll ans = 1;
	while(e)
	{
		if(e & 1)
			ans = ans * x % mod;
		x = x * x % mod;
		e /= 2;
	}
	return ans;
}

bool is_root(int x, int mod)
{
	mod--;
	//std::cout << "testando " << x << " em " << mod << '\n';
	for(int i = 0; i + 1 < divs[mod].size(); i++)
	{
		if(fexp(x, divs[mod][i], mod + 1) == 1)
		{
			//std::cout << "deu pau em " << divs[mod][i] << '\n';
			return false;
		}
	}
	return true;
}

int get_root(int mod)
{
	int ans = mod - 1;
	while(!is_root(ans, mod))
		ans--;
	return ans;
}

int gcd(int a, int b)
{
	if(!b)
		return a;
	else
		return gcd(b, a % b);
}

ll modinverse(ll a, ll b, ll s0 = 1, ll s1 = 0)
{
    if(!b)
        return s0;
    else
        return modinverse(b, a % b, s1, s0 - s1 * (a / b));
}

int a[ms];

//int all[3000];
//int got[3000];
int memo[3000];
int to[3000];
std::set<int> nums[3000];

int dp(int on)
{
	int &ans = memo[on];
	if(ans != -1)
		return ans;
	ans = 0;
	to[on] = divs[m].size();
	for(int i = on + 1; i < divs[m].size(); i++)
	{
		if(divs[m][i] % divs[m][on] != 0)
			continue;
		if(dp(i) > ans)
		{
			ans = dp(i);
			to[on] = i;
		}
	}
	ans += nums[on].size();
	//std::cout << "from " << divs[m][on] << " to " << divs[m][to[on]] << ", ans is " << ans << '\n';
	return ans;
}

int main()
{
	for(int i = 1; i < ms; i++)
	{
		for(int j = i; j < ms; j += i)
		{
			divs[j].push_back(i);
			if(divs[i].size() == 2)
				primes[j].push_back(i);
		}
	}
	while(std::cin >> n >> m)
	{
		//std::cout << "root of " << m << " is " << get_root(m) << '\n';
		//memset(got, 0, sizeof got);
		memset(memo, -1, sizeof memo);
		//memset(all, 0, sizeof all);
		std::map<int, int> div_ind;
		for(int i = 0; i < divs[m].size(); i++)
		{
			div_ind[divs[m][i]] = i;
			nums[i].clear();
		}
		for(int i = 0; i < n; i++)
			//std::cin >> a[i];
			scanf("%i", a + i);
		for(int i = 0; i < m; i++)
			nums[div_ind[gcd(i, m)]].insert(i);
		for(int i = 0; i < n; i++)
			nums[div_ind[gcd(a[i], m)]].erase(a[i]);
		/*for(int i = 0; i < m; i++)
			all[div_ind[gcd(i, m)]]++;
		for(int i = 0; i < n; i++)
			got[div_ind[gcd(a[i], m)]]++;*/

		//for(int i = 0; i < divs[m].size(); i++)
		//	std::cout << divs[m][i] << ": (" << got[i] << ", " << all[i] << ")\n";
		
		dp(0);
		std::vector<int> ans;
		std::vector<int> anss;
		for(int on = 0; on < divs[m].size(); on = to[on])
		{
			if(!nums[on].size())
				continue;
			for(std::set<int>::iterator it = nums[on].begin(); it != nums[on].end(); it++)
			{
				if(!ans.size() || *it == 0)
				{
					ans.push_back(*it);
					anss.push_back(*it);
					continue;
				}
				ll cur = ans.back();
				ll nxt = modinverse(cur, m);
				nxt = (nxt % m + m) % m;
				cur = cur * nxt % m;
				nxt = nxt * ((*it) / cur);
				nxt %= m;
				ans.push_back(*it);
				anss.push_back(nxt);
			}
		}
		std::cout << anss.size() << '\n';
		for(int i = 0; i < anss.size(); i++)
		{
			if(i)
				printf(" ");
			printf("%i", anss[i]);
		}
		std::cout << '\n';
		//std::cout << "ans is " << dp(0) << '\n';
	}
}