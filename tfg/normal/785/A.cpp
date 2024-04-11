#include <iostream>
#include <string>

int m[256];

int main()
{
	int n;
	std::cin >> n;
	int ans=0;
	m['T']=4;
	m['C']=6;
	m['O']=8;
	m['D']=12;
	m['I']=20;
	while(n--)
	{
		std::string str;
		std::cin >> str;
		ans+=m[str[0]];
	}
	std::cout << ans << '\n';
}