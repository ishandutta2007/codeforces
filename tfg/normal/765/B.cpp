#include <iostream>
#include <string>

int cur='a'-1;
int freq[256];

int main()
{
	std::string str;
	std::cin >> str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]<=cur)
			continue;
		else if(str[i]!=cur+1)
		{
			std::cout << "NO\n";
			return 0;
		}
		else
			cur++;
	}
	std::cout << "YES\n";
	return 0;

}