#include <iostream>
#include <string>
#include <vector>

int n;
std::string str;

int main()
{
	std::cin >> n >> str;
	std::vector<int> ans;
	int b=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='W')
		{
			if(b)
				ans.push_back(b);
			b=0;
		}
		else
		{
			b++;
		}
	}
	if(b) ans.push_back(b);
	std::cout << (int)ans.size() << '\n';
	for(int i=0;i<ans.size();i++)
	{
		if(i) std::cout << ' ';
		std::cout << ans[i];
	}
	std::cout << '\n';
}