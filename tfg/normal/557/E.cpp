#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

const int ms=5050;

std::string str;
int n, k;

std::vector<int> a[2][ms];

int memo[ms][ms];

int dp(int l, int r)
{
	//std::cout << "on dp(" << l << ", " << r << ")\n";
	if(l>=r)
		return 1;
	int &ans=memo[l][r];
	if(ans!=-1)
		return ans;
	if(str[l]==str[r] && dp(l+2, r-2))
		ans=1;
	else
		ans=0;
	return ans;
}

int propagate(int on, int type)
{
	//std::cout << "prop (" << on << ", " << type << ")\n";
	int got=0;
	
	while(a[type][on].size())
	{
		int cur=a[type][on].back();
		if(dp(cur,cur+on))
			got++;
		if(cur+on+1<str.size())
		{
			a[str[cur+on+1]][on+1].push_back(cur);
			//std::cout << cur << " to (" << on+1 << ", " << int(str[cur+on+1]) << ")\n";
		}
		a[type][on].pop_back();
	}
	return got;
}



int main()
{
	memset(memo, -1, sizeof memo);
	std::cin >> str >> k;
	n=str.size();
	for(int i=0;i<n;i++)
	{
		str[i]-='a';
		a[str[i]][0].push_back(i);
	}
	int on=0;
	//std::vector<char> deb;
	while(1)
	{
		int got=0;
		int start=0;
		//for(int i=0;i<deb.size();i++)
		//	std::cout << deb[i];
		//std::cout << ": " << k << '\n';
		if(a[0][on].size())
		{
			//deb.push_back('a');
			start=a[0][on].back();
			got=propagate(on, 0);
		}
		else if(a[1][on].size())
		{
			//deb.push_back('b');
			start=a[1][on].back();
			got=propagate(on, 1);
		}
		else
		{
			//deb.pop_back();
			on--;
			continue;
		}
		if(got<k)
			k-=got;
		else
		{
			//std::cout << "found ans\n";
			std::string hmm;
			for(int i=0;i<=on;i++)
				hmm+=str[start+i]+'a';
			std::cout << hmm << '\n';
			return 0;
		}
		on++;
	}
}