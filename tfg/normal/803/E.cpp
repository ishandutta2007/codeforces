#include <iostream>
#include <cstring>
#include <string>

const int ms = 1010;

int n, k;

std::string str;

int memo[ms][2*ms];
int to[ms][2*ms];
int dp(int on, int balance)
{
	int &ans = memo[on][ms + balance];
	if(ans != -1)
		return ans;
	if(on == n)
	{
		if(balance == k || balance == -k)
			return ans = 1;
		else
			return ans = 0;
	}
	if(balance == k || balance == -k)
		return ans = 0;
	if(str[on] == 'L')
	{
		to[on][ms + balance] = -1;
		ans = dp(on + 1, balance - 1);
	}
	else if(str[on] == 'W')
	{
		to[on][ms + balance] = 1;
		ans = dp(on + 1, balance + 1);
	}
	else if(str[on] == 'D')
	{
		to[on][ms + balance] = 0;
		ans = dp(on + 1, balance);
	}
	else
	{
		if(dp(on + 1, balance - 1))
			to[on][ms + balance] = -1;
		else if(dp(on + 1, balance))
			to[on][ms + balance] = 0;
		else if(dp(on + 1, balance + 1))
			to[on][ms + balance] = 1;
		else
			to[on][ms + balance] = 2;
		if(to[on][ms + balance] == 2)
			ans = 0;
		else
			ans = 1;
	}
	return ans;
}



int main()
{
	while(std::cin >> n >> k >> str)
	{
		memset(memo, -1, sizeof memo);
		bool can = dp(0, 0) == 1;
		if(!can)
		{
			std::cout << "NO\n";
			return 0;
		}
		int balance = 0;
		std::string ans;
		for(int on = 0; on < n; on++)
		{
			if(to[on][ms + balance] == -1)
				ans += 'L';
			else if(to[on][ms + balance] == 0)
				ans += 'D';
			else
				ans += 'W';
			balance += to[on][ms + balance];
		}
		std::cout << ans << '\n';
	}
}