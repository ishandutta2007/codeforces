#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

std::vector<int> pos;

int main()
{
	srand(time(NULL));
	int n, start, x;
	std::cin >> n >> start >> x;
	for(int i = 1; i <= n; i++)
	{
		if(i == start)
			continue;
		pos.push_back(i);
	}
	int nxt;
	int l = start;
	std::cout << "? " << start << std::endl;
	int val;
	std::cin >> val >> nxt;
	if(val >= x)
	{
		std::cout << "! " << val << std::endl;
		return 0;
	}
	for(int i = 0; i < 1200 && pos.size() > 0; i++)
	{
		int on = (rand() ^ (rand() << 15)) % pos.size();
		std::cout << "? " << pos[on] << std::endl;
		int v;
		std::cin >> v >> nxt;
		if(v < x && v > val)
		{
			val = v;
			start = pos[on];
		}
		std::swap(pos[on], pos.back());
		pos.pop_back();
	}
	int got = 1200;
	while(1)
	{
		if(got >= 1996)
		{
			std::cout << "! -1" << std::endl;
			return 0;
		}
		//assert(got < 1980);
		got++;
		std::cout << "? " << start << std::endl;
		int v;
		std::cin >> v >> nxt;
		if(v >= x)
		{
			std::cout << "! " << v << std::endl;
			return 0;
		}
		else if(nxt == -1)
		{
			std::cout << "! -1" << std::endl;
			return 0;
		}
		start = nxt;
	}
}