#include <iostream>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	bool ans = false;
	while(n--)
	{
		std::string str;
		int bef, aft;
		std::cin >> str >> bef >> aft;
		ans = ans || (bef >= 2400 && aft > bef);
	}
	if(ans)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}