#include <iostream>
#include <algorithm>


int main()
{
	std::string s1, s2;
	std::cin >> s1 >> s2;
	if(s1==s2)
		std::cout << "-1\n";
	else
		std::cout << std::max(s1.size(), s2.size()) << '\n';
}