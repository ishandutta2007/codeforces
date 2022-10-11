#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> cost[2];
int zeros = 0;

int main()
{
	int n, dist, tot;
	std::cin >> n >> dist >> tot;
	int ori = tot;
	int tot_cap = 0;
	for(int i = 0; i < n; i++)
	{
		int cap, fuel, len;
		std::cin >> cap >> fuel >> len;
		len = (len >= dist ? 1 : 0);
		//std::cout << "(" << cap << ", " << fuel << ", " << len << ")\n";
		if(cap == 0)
		{
			zeros++;
			if(len == 1)
				cost[1].push_back(fuel);
			else
				cost[1].push_back(tot + 1);
		}
		else
		{
			tot_cap = std::min(cap + tot_cap, n);
			if(len == 1)
			{
				cost[0].push_back(fuel);
				cost[1].push_back(fuel);
			}
		}
	}
	std::sort(cost[0].begin(), cost[0].end());
	std::sort(cost[1].begin(), cost[1].end());
	if(cost[0].size() == 0 || cost[0][0] > tot)
	{
		//std::cout << "first case\n";
		int ans = 0;
		for(int i = 0; i < cost[1].size(); i++)
		{
			if(cost[1][i] <= tot)
			{
				tot -= cost[1][i];
				ans++;
			}
			else
			{
				break;
			}
		}
		std::cout << ans << ' ' << ori - tot << '\n';
	}
	else
	{
		//std::cout << "second case\n";
		int usual = n - 1 - zeros;
		int ans = usual + 1;
		tot -= cost[0][0];
		tot_cap -= usual;
		int use = std::min(zeros, tot_cap);
		tot_cap -= use;
		zeros -= use;
		ans += use;
		bool skip = false;
		for(int i = 0; i < cost[1].size() && zeros; i++)
		{
			if(cost[1][i] == cost[0][0] && !skip)
			{
				skip = true;
				continue;
			}
			if(cost[1][i] <= tot)
			{
				tot -= cost[1][i];
				ans++;
				zeros--;
			}
			else
			{
				break;
			}
		}
		int hmm = ori;
		int hmm2 = 0;
		for(int i = 0; i < cost[1].size(); i++)
		{
			if(cost[1][i] <= hmm)
			{
				hmm -= cost[1][i];
				hmm2++;
			}
			else
				break;
		}
		if(hmm2 > ans)
		{
			ans = hmm2;
			tot = hmm;
		}
		std::cout << ans << ' ' << ori - tot << '\n';
	}
}