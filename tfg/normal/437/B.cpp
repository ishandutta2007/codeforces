#include <iostream>
#include <vector>
#include <cstdio>

const int ms=100100;

int sum, limit;

std::vector<int> numbers[ms];

int main()
{
	std::cin >> sum >> limit;

	for(int i=1;i<=limit;i*=2)
	{
		for(int j=i;j<=limit;j+=i+i)
			numbers[i].push_back(j);
	}

	int on=0;
	std::vector<int> ans;
	for(int i=limit;i>0;i--)
	{
		for(int j=0;j<numbers[i].size() && on+i<=sum;j++)
		{
			ans.push_back(numbers[i][j]);
			on+=i;
		}
	}
	if(on==sum)
	{
		std::cout << int(ans.size()) << '\n';
		for(int i=0;i<ans.size();i++)
		{
			if(i)
				printf(" ");
				//std::cout << ' ';
			//std::cout << ans[i];
			printf("%i",ans[i]);
		}
	}
	else
		std::cout << "-1";
	std::cout << '\n';
}