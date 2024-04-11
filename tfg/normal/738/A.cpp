#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	int n;
	std::string str;
	std::cin >> n >> str;
	int match=0;
	std::vector<char> ans;
	for(int i=0;i<str.size();i++)
	{
		int prv=match;
		if(match&1)
		{
			if(str[i]=='g')
				match++;
			else if(str[i]=='o')
				match=1;
			else
				match=0;
		}
		else
		{
			if(str[i]=='o')
				match++;
			else
				match=0;
		}
		if(prv>=3 && match<=1)
		{
			for(int j=0;j<3;j++)
				ans.push_back('*');
			if(prv%2==0)
				ans.push_back(str[i-1]);
		}
		if(match==3)
		{
			for(int j=0;j<2;j++)
				ans.pop_back();
		}
		else if(match<3)
			ans.push_back(str[i]);
	}
	if(match>=3)
	{
		for(int j=0;j<3;j++)
			ans.push_back('*');
		if(match%2==0)
			ans.push_back(str[n-1]);
	}
	for(int i=0;i<ans.size();i++)
		std::cout << ans[i];
	std::cout << '\n';
}