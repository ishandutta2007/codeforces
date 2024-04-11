#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::vector<int> vi;
typedef std::pair<vi, vi> vv;

int main()
{
	int n;
	std::cin >> n;
	vi a[2];
	for(int i=0;i<2;i++)
	{
		int size;
		std::cin >> size;
		while(size--)
		{
			int temp;
			std::cin >> temp;
			a[i].push_back(temp);
		}
	}

	std::map<vv, bool> dude;
	long long step=0;
	while(a[0].size()!=0 && a[1].size()!=0 && dude[vv(std::min(a[0],a[1]), std::max(a[0],a[1]))] == false)
	{
		/*std::cout << "on step " << step << ":\n";
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<a[i].size();j++)
				std::cout << a[i][j] << ' ';
			std::cout << '\n';
		}*/
		dude[vv(std::min(a[0],a[1]), std::max(a[0],a[1]))] = true;
		if(a[0][0] > a[1][0])
		{
			a[0].push_back(a[1][0]);
			a[0].push_back(a[0][0]);
		}
		else
		{
			a[1].push_back(a[0][0]);
			a[1].push_back(a[1][0]);
		}
		a[0].erase(a[0].begin());
		a[1].erase(a[1].begin());
		step++;
	}


	if(a[0].size()==0)
		std::cout << step << ' ' << 2;
	else if(a[1].size()==0)
		std::cout << step << ' ' << 1;
	else
		std::cout << -1;

	std::cout << '\n';
}