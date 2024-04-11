#include <iostream>
#include <map>
#include <utility>

typedef std::pair<int, int> ii;

ii a[100100];

int main()
{
	std::map<ii, int> hmm;
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		std::cin >> a[i].first >> a[i].second;
		hmm[a[i]] = i;
	}
	int ans = -1;
	for(int i = 0; i < m; i++)
	{
		int cur = i;
		bool flag = true;
		for(int j = 0; j < 3 && flag; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				auto it = hmm.find(ii(a[i].first + j, a[i].second + k));
				if(it == hmm.end())
				{
					//std::cout << "for " << i << " broke on " << j << ", " << k << "\n";
					flag = false;
					break;
				}
				cur = std::max(cur, it->second);
			}
		}
		if(flag)
		{
			//std::cout << "found on " << i << "\n";
			if(ans == -1 || cur + 1 < ans)
				ans = cur + 1;
		}
	}
	std::cout << ans << '\n';
}