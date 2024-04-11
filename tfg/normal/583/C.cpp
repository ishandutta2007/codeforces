#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> nums;
std::vector<int> ans;
std::map<int, int> exclude;

int gcd(int a, int b)
{
	if(a<b) return gcd(b, a);
	if(b==0) return a;
	return gcd(b, a%b);
}

int main()
{
	int n;
	scanf("%i", &n);
	for(int i=0;i<n*n;i++)
	{
		int temp;
		scanf("%i", &temp);
		nums.push_back(temp);
	}
	std::sort(nums.begin(), nums.end());
	for(int i=0;i<n;i++)
	{
		while(exclude[nums.back()]>0)
		{
			exclude[nums.back()]--;
			nums.pop_back();
		}
		ans.push_back(nums.back());
		nums.pop_back();
		for(int j=0;j<ans.size()-1;j++)
		{
			exclude[gcd(ans.back(),ans[j])]+=2;
		}
	}
	for(int i=0;i<n;i++)
		printf("%i ", ans[i]);
}