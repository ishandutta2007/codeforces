#include <iostream>
#include <vector>
#include <string>

int n;
std::string str;
std::vector<int> pac, want;

bool can(int x)
{
	int on = 0;
	for(auto a : pac)
	{
		if(on == want.size())
			return true;
		if(want[on] < a - x)
			return false;
		int first = std::min(a, want[on]);
		while(on < want.size() && want[on] < a)
			on++;
		while(on < want.size() && 2 * std::min(want[on] - a, a - first) + std::max(want[on] - a, a - first) <= x)
			on++;
	}
	if(on == want.size())
		return true;
	else
		return false;
}

int main()
{
	std::cin >> n >> str;
	for(int i = 0; i < n; i++)
	{
		if(str[i] == 'P')
			pac.push_back(i);
		else if(str[i] == '*')
			want.push_back(i);
	}
	int l = 0, r = 2 * n;
	while(l != r)
	{
		int mid = (l + r) / 2;
		if(can(mid))
			r = mid;
		else
			l = mid + 1;
	}
	std::cout << l << '\n';
}