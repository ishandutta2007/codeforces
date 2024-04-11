#include <iostream>
#include <string>
#include <algorithm>

std::string str;

bool is_v(char x)
{
	return x=='A' || x=='E' || x=='I' || x=='O' || x=='U' || x=='Y';
}

int main()
{
	std::cin >> str;
	int left=-1;
	int ans=0;
	for(int i=0;i<str.size();i++)
	{
		if(is_v(str[i]))
		{
			ans=std::max(ans,i-left);
			left=i;
		}
	}
	ans=std::max(ans,(int)str.size()-left);
	std::cout << ans << std::endl;
}