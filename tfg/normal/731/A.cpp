#include <cstdio>
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>

typedef long long int ll;
typedef std::pair<int, int> ii;

int main()
{
	std::string str;
	int now=0;
	int MOD='z'-'a'+1;
	int steps=0;
	std::cin >> str;
	for(int i=0;i<str.size();i++)
	{
		steps+=std::min((now-(str[i]-'a')+MOD)%MOD,(-now+(str[i]-'a')+MOD)%MOD);

		now=str[i]-'a';
	}
	std::cout << steps << std::endl;
}