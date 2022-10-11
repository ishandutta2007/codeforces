#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

const int ms = 100100;

std::vector<int> edges[ms];
int par[ms], h[ms], H = 0;

void dfs(int on, int height = 0)
{
	h[on] = height;
	for(int i = 0; i < edges[on].size(); i++)
		dfs(edges[on][i], height + 1);
	H = std::max(H, height);
}

ll a[ms], nimber = 0;

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		int u;
		std::cin >> u;
		u--;
		edges[u].push_back(i);
	}
	dfs(0);
	std::vector<int> nums[2];
	for(int i = 0; i < n; i++)
	{
		h[i] += H + 1;
		nums[h[i] % 2].push_back(a[i]);
	}
	std::map<int, int> freq;
	ll ans = 0;
	for(int i = 0; i < nums[1].size(); i++)
	{
		//std::cout << "on odd got " << nums[1][i] << '\n';
		nimber ^= nums[1][i];
		freq[nums[1][i]]++;
	}
	if(nimber == 0)
		ans += ((ll) nums[0].size() * (ll) (int(nums[0].size()) - 1) + (ll) nums[1].size() * (ll) (int(nums[1].size()) - 1)) / 2;
	for(int i = 0; i < nums[0].size(); i++)
	{
		//std::cout << "on even got " << nums[0][i] << '\n';
		// nimber ^ x ^ num == 0
		ans += freq[nimber ^ nums[0][i]];
	}
	std::cout << ans << '\n';
}