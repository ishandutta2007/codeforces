#include <iostream>
#include <vector>

std::vector<int> ans;

int main()
{
	int n;
	std::cin >> n;
	while(n>3 || n==2)
	{
		n-=2;
		ans.push_back(2);
	}
	if(n==3)
	{
		ans.push_back(3);
	}
	std::cout << int(ans.size()) << '\n';
	for(int i=0;i<ans.size();i++)
	{
		if(i)
			std::cout << ' ';
		std::cout << ans[i];
	}
	std::cout << '\n';
}