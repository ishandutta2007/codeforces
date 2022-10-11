#include <iostream>
#include <queue>
#include <iomanip>
#include <cstdio>

const int ms = 1001000;

std::vector<int> pos[ms];
int a[ms], idx[ms];

int main()
{
	int n;
	std::cin >> n;
	long long ans = 0, cur = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%i", a + i);
		//std::cin >> a[i];
		if(pos[a[i]].empty())
			cur += n - i;
		pos[a[i]].push_back(i);
	}
	for(int i = 0; i < n; i++)
	{
		ans += cur;
		cur -= n - i;
		idx[a[i]]++;
		if(idx[a[i]] != pos[a[i]].size())
			cur += n - pos[a[i]][idx[a[i]]];
	}
	std::cout << std::fixed << std::setprecision(15) << (2 * ans - n) / ((double)n * n) << '\n';
}