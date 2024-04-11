#include <iostream>
#include <set>
#include <utility>
#include <vector>

typedef std::pair<int, int> ii;

const int ms = 100100;

ii coord[2*ms];
int freq[2*ms];

int main()
{
	for(int i = 1; i < ms; i++)
		coord[i + ms].second = coord[ms - i].first = i;
	int n;
	std::cin >> n;
	std::set<ii> points;
	for(int i = 0; i < n; i++)
	{
		ii cur;
		std::cin >> cur.first >> cur.second;
		points.insert(cur);
	}
	std::vector<ii> ans;
	std::multiset<ii> good;
	good.insert(ii(0, 0));
	for(int i = 0; i < n; i++)
	{
		int cur;
		std::cin >> cur;
		cur += ms;
		if(
			good.count(coord[cur]) < (std::min(coord[cur].first, coord[cur].second) == 0 ? 1 : 2)
			|| !points.count(coord[cur]))
		{
			std::cout << "NO\n";
			return 0;
		}
		good.insert(ii(coord[cur].first + 1, coord[cur].second));
		good.insert(ii(coord[cur].first, coord[cur].second + 1));
		ans.push_back(coord[cur]);
		coord[cur].first++;
		coord[cur].second++;
	}
	std::cout << "YES\n";
	for(int i = 0; i < ans.size(); i++)
		std::cout << ans[i].first << ' ' << ans[i].second << '\n';
}