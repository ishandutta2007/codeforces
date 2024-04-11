#include <iostream>
#include <string>

std::string str;

int main()
{
	std::cin >> str;
	long long ans='z'-'a'+1;
	for(int i=0;i<str.size();i++)
	{
		ans+='z'-'a';
	}
	std::cout << ans << '\n';
}