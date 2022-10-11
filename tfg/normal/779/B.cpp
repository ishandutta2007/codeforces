#include <iostream>
#include <string>
#include <algorithm>

std::string n;
int k;

bool visit[1010][1010];
int memo[1010][1010];

int dp(int on, int back)
{
	if(on==n.size())
	{
		if(back>=k)
			return 0;
		else
			return 1010;
	}
	int &ans=memo[on][back];
	if(visit[on][back])
		return ans;
	visit[on][back]=true;
	ans=1+dp(on+1,back);
	if(n[on]=='0')
		ans=std::min(dp(on+1, back+1),ans);
	else
		ans=std::min(dp(on+1, 0),ans);
	return ans;
}

int main()
{
	std::cin >> n >> k;
	int ans=dp(0,0);
	if(ans>=1010)
	{
		ans=n.size()-1;
	}
	std::cout << ans << '\n';
}