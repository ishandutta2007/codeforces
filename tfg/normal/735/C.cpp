#include <iostream>

long long int n;

long long int memo[2000];
bool visit[2000];

long long int dp(int on)
{
	if(on<=0) return 1;
	if(visit[on]) return memo[on];
	visit[on]=true;
	return memo[on]=dp(on-1)+dp(on-2);
}

int main()
{
	std::cin >> n;
	int ans=0;
	long long int max=(long long int)1e18+10;
	for(int i=0;1;i++)
	{
		if(dp(i)>n)
		{
			ans=i-1;
			break;
		}
	}
	
	std::cout << ans << '\n';
}