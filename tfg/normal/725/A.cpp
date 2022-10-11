#include <string>
#include <iostream>

std::string str;

int main()
{
	int ans;
	std::cin >> ans;
	ans=0;
	std::cin >> str;
	int i=0;
	while(str[i]=='<' && i<str.size())
	{
		ans++;
		i++;
	}
	i=(int)str.size()-1;
	while(str[i]=='>' && i>=0)
	{
		i--;
		ans++;
	}
	std::cout << ans << std::endl;
}