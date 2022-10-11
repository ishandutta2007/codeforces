#include <iostream>
#include <cstdio>
#include <vector>

int n,a,b,k;
char str[2*int(1e5)+10];

int main()
{
	std::cin >> n >> a >> b >> k;
	scanf(" %s",str);
	int cur_sum=0;
	int total=0;
	std::vector<int> ans;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='1')
		{
			total+=cur_sum/b;
			cur_sum=0;
		}
		else
		{
			cur_sum++;
			if(cur_sum%b==0)
				ans.push_back(i+1);
		}
	}
	total+=cur_sum/b;
	total=std::max(0,total-a+1);
	std::cout << total << '\n';
	for(int i=0;i<total;i++)
	{
		if(i!=0)
			printf(" ");
		printf("%i",ans[i]);
	}
	std::cout << '\n';
}