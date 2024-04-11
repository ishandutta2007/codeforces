#include <iostream>
#include <vector>

typedef long long int ll;

int n;
ll k;

ll memo[55];
bool visit[55];

ll dp(int on)
{
	if(on>=n)
		return 1;
	ll &ans=memo[on];
	if(visit[on])
		return ans;
	visit[on]=true;
	ans=dp(on+1);
	if(on+2<=n)
		ans+=dp(on+2);
	return ans;
}

int main()
{
	std::cin >> n >> k;
	std::vector<int> ans;
	dp(0);
	for(int i=0;i<n;i++)
	{
		if(k<=dp(i+1))
			ans.push_back(i+1);
		else
		{
			ans.push_back(i+2);
			ans.push_back(i+1);
			k-=dp(i+1);
			i++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i)
			std::cout << ' ';
		std::cout << ans[i];
	}
	std::cout << '\n';
}