#include <iostream>
#include <string>

const int ms=500500;

std::string str[ms], ans[ms];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
		std::cin >> str[i];
	ans[n-1]=str[n-1];
	for(int i=n-2;i>=0;i--)
	{
		int type=0;
		int to=0;
		for(;to<str[i].size() && to<ans[i+1].size();to++)
		{
			if(str[i][to]<ans[i+1][to])
				type=1;
			else if(str[i][to]>ans[i+1][to])
				type=2;
			if(type)
				break;
		}
		if(type==0 || type==2)
		{
			for(int j=0;j<to;j++)
				ans[i]+=str[i][j];
		}
		else if(type==1)
		{
			ans[i]=str[i];
		}
		//std::cout << i << ": " << ans[i] << '\n';
	}
	for(int i=0;i<n;i++)
		std::cout << ans[i] << '\n';
}