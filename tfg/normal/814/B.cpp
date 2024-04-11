#include <iostream>
#include <utility>
#include <vector>
#include <cassert>

typedef std::pair<int, int> ii;

const int ms = 1010;

int to[ms];

int getmissing(std::vector<int> a)
{
	for(int i = 0; i < a.size(); i++)
		to[i + 1] = 1;
	for(int i = 0; i < a.size(); i++)
		to[a[i]] = 0;
	for(int i = 0; i < a.size(); i++)
	{
		if(to[i + 1])
			return i + 1;
	}
	return 0;
}

int diff(std::vector<int> a, std::vector<int> b)
{
	int ans = 0;
	for(int i = 0; i < a.size(); i++)
		ans += a[i] == b[i] ? 0 : 1;
	return ans;
}

int main()
{
	int n;
	while(std::cin >> n)
	{
		std::vector<int> a[2];
		for(int i = 0; i < 2; i++)
		{
			a[i].resize(n);
			for(int j = 0; j < n; j++)
				std::cin >> a[i][j];
		}
		int miss = getmissing(a[0]);
		for(int i = 0; i < n; i++)
		{
			int temp = a[0][i];
			a[0][i] = miss;
			if(getmissing(a[0]) == 0 && diff(a[0], a[1]) == 1)
				break;
			a[0][i] = temp;
		}
		assert(diff(a[0], a[1]) == 1);
		assert(miss);
		for(int i = 0; i < n; i++)
		{
			if(i)
				std::cout << " ";
			std::cout << a[0][i];
		}
		std::cout << '\n';
	}
}