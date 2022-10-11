#include <iostream>
#include <map>
#include <cstdio>

std::map<int, int> table;

int main()
{
	int n;
	std::cin >> n;
	n+=n;
	int ans=0;
	int cur=0;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%i",&temp);
		cur-=table[temp];
		table[temp]=(table[temp]+1)%2;
		cur+=table[temp];
		ans=std::max(ans, cur);
	}
	std::cout << ans << '\n';
}