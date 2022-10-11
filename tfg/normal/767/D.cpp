#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ii;

std::vector<ii> buy;
std::vector<int> normal, bu;

int n, m, k;

bool f(int b)
{
	std::vector<int> nums(n+b, -1);
	std::merge(bu.end()-b,bu.end(),normal.begin(),normal.end(),nums.begin());
	//for(int i=0;i<nums.size();i++) std::cout << nums[i] << ' ';std::cout << '\n';
	int on=0;
	for(int i=0;i<nums.size();i+=k, on++)
	{
		if(nums[i]<on)
			return false;
	}
	return true;
}

int main()
{
	
	std::cin >> n >> m >> k;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%i", &temp);
		normal.push_back(temp);
	}
	for(int i=0;i<m;i++)
	{
		int temp;
		scanf("%i", &temp);
		buy.push_back(ii(temp, i+1));
		bu.push_back(temp);
	}
	std::sort(buy.begin(), buy.end(), std::greater<ii>());
	std::sort(bu.begin(), bu.end());
	std::sort(normal.begin(), normal.end());
	if(!f(0))
	{
		std::cout << "-1\n";
		return 0;
	}
	int l=0, r=m;
	while(l!=r)
	{
		int mid=(l+r+1)/2;
		if(f(mid))
			l=mid;
		else
			r=mid-1;
	}
	std::cout << l << '\n';
	for(int i=0;i<l;i++)
	{
		if(i)
			printf(" ");
		printf("%i", buy[i].second);
	}
}