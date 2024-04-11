#include <iostream>
#include <string>
#include <map>
#include <algorithm>

const int ms = 16;

int can[ms];
std::string names[ms];
std::map<std::string, int> rep;

bool les(int a, int b)
{
	for(int i = 0; i < ms; i++)
	{
		int cura = a & 1;
		int curb = b & 1;
		if(cura != curb)
			return cura > curb;
		a >>= 1;
		b >>= 1;
	}
	return false;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		std::cin >> names[i];
		can[i] = (1 << n) - 1;
	}
	std::sort(names, names + n);
	for(int i = 0; i < n; i++)
		rep[names[i]] = i;
	for(int i = 0; i < m; i++)
	{
		std::string str[2];
		std::cin >> str[0] >> str[1];
		int u = rep[str[0]];
		int v = rep[str[1]];
		can[u] ^= 1 << v;
		can[v] ^= 1 << u;
	}
	int ans = 1;
	int mask = 1;
	for(int i = 0; i < (1 << n); i++)
	{
		int cur_ans = 0;
		int cur_mask = (1 << n) - 1;
		for(int j = 0; j < n; j++)
		{
			if(i & (1 << j))
			{
				cur_ans++;
				cur_mask = cur_mask & can[j];
			}
		}
		if((i & cur_mask) == i && (cur_ans > ans || (cur_ans == ans && les(i, mask))))
		{
			ans = cur_ans;
			mask = i;
		}
	}
	std::cout << ans << '\n';
	for(int i = 0; i < n; i++)
	{
		if(mask & (1 << i))
			std::cout << names[i] << '\n';
	}
}