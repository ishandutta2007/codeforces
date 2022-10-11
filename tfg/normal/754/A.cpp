#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int,int> ii;

int a[1010];

int main()
{
	int n;
	std::cin >> n;
	int start=1;
	bool valid=false;
	int got=0;
	std::vector<ii> ans;
	for(int i=1;i<=n;i++)
	{
		std::cin >> a[i];
		if(a[i])
		{
			valid=true;
			got++;
			if(got==1)
				continue;
			ans.push_back(ii(start, i-1));
			start=i;
		}
	}
	ans.push_back(ii(start, n));
	if(valid)
	{
		std::cout << "YES\n" << int(ans.size()) << '\n';
		for(int i=0;i<ans.size();i++)
			std::cout << ans[i].first << " " << ans[i].second << '\n';
	}
	else
		std::cout << "NO\n";
}