#include <iostream>
#include <set>
#include <string>

int main()
{
	int n;
	std::set<std::string> names;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		if(names.count(str))
			std::cout << "YES\n";
		else
		{
			std::cout << "NO\n";
			names.insert(str);
		}
	}

}