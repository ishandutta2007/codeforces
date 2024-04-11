#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

int great[3][100][100];

std::vector<int> dude[3];

std::string str;
int n;

int memo[100][100][100][2];

int get_pos(int v, int k, int o, int pos)
{
	return (great[0][pos][v]+great[1][pos][k]+great[2][pos][o] + pos);
}

int cost(int v, int k, int o, int pos, int to)
{
	return abs(to - get_pos(v, k, o, pos));
}

int dp(int v, int k, int o, int past)
{
	if(v+k+o==n)
		return 0;
	int &ans=memo[v][k][o][past];
	if(ans!=-1)
		return ans;
	ans = 210983;
	int nxt=v+k+o;
	if(v<dude[0].size())
		ans = std::min(ans, cost(v, k, o, dude[0][v], nxt) + dp(v+1, k, o, 1));
	if(k<dude[1].size() && !past)
		ans = std::min(ans, cost(v, k, o, dude[1][k], nxt) + dp(v, k+1, o, 0));
	if(o<dude[2].size())
		ans = std::min(ans, cost(v, k, o, dude[2][o], nxt) + dp(v, k, o+1, 0));
	return ans;
}

int main()
{
	memset(memo, -1, sizeof memo);
	std::cin >> n >> str;
	for(int i=0;i<n;i++)
	{
		int to;
		if(str[i]=='V')
			to=0;
		else if(str[i]=='K')
			to=1;
		else
			to=2;
		dude[to].push_back(i);
	}
	for(int t=0;t<3;t++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=dude[t].size();j++)
			{
				for(int k=0;k<j;k++)
				{
					int on=dude[t][k];
					if(on>i)
						great[t][i][j]++;
				}
			} 
		}
	}
	std::cout << dp(0, 0, 0, 0) << '\n';
}