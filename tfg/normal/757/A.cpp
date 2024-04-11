#include <iostream>
#include <string>
#include <algorithm>

std::string str, b;

int freq[256];

int main()
{
	std::cin >> str;
	for(int i=0;i<str.size();i++)
	{
		freq[str[i]]++;
	}


	b="Bulbasaur";
	int ans=100000;
	for(int i=0;i<b.size();i++)
	{
		ans=std::min(ans, freq[b[i]]);
	}

	ans=std::min(ans, freq['u']/2);
	ans=std::min(ans, freq['a']/2);

	std::cout << ans << '\n';
}