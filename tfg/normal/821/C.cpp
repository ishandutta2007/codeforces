#include <iostream>
#include <string>
#include <set>
#include <stack>
#include <vector>
#include <cstdio>

char str[12903];

int main()
{
	std::vector<int> s;
	std::set<int> ord;
	int n;
	std::cin >> n;
	int want = 1, ans = 0;
	for(int i = 0; i < 2 * n; i++)
	{
		//std::cout << "on command " << i << '\n';
		//std::string str;
		//std::cin >> str;
		scanf(" %s", str);
		if(str[0] == 'r')
		{
			if(!s.empty())
			{
				//std::cout << "stack isn't empty\n";
				if(s.back() == want)
				{
					s.pop_back();
					//std::cout << "got wanted\n";
				}
				else
				{
					s.clear();
					ans++;
					//std::cout << "reordered\n";
				}
			}
			ord.erase(want);
			want++;
		}
		else
		{
			int to;
			//std::cin >> to;
			scanf("%i", &to);
			s.push_back(to);
			ord.insert(to);
		}
	}
	std::cout << ans << '\n';
}