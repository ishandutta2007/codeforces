#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

typedef long long int ll;

const ll MOD=ll(1e9)+7;

const int ms=5050;
const int eps='z'-'a'+2;

int n;
std::string str;
std::vector<int> types;
int to[ms][eps];

ll memo[ms][ms];

ll sum[eps];
ll mem_sum[ms];
int last[eps];

int main()
{
	std::cin >> n >> str;
	types.push_back(str[0]-'a');
	for(int i=1;i<str.size();i++)
	{
		if(str[i]!=str[i-1])
			types.push_back(str[i]-'a');
	}
	

	/*for(int i=0;i<types.size();i++)
	{
		if(sum[types[i]])
			continue;
		sum[types[i]]++;
		memo[0][i]++;
	}*/

	memo[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<eps;j++)
		{
			sum[j]=0;
			last[j]=0;
		}
		mem_sum[0]=0;
		for(int j=0;j<types.size();j++)
			mem_sum[j+1]=(mem_sum[j]+memo[i-1][j])%MOD;
		for(int j=0;j<int(types.size());j++)
		{
			memo[i][j]=(mem_sum[j+1]-mem_sum[last[types[j]]]+MOD)%MOD;
			last[types[j]]=j+1;
			//std::cout << memo[i][j] << ' ';
		}
		//std::cout << '\n';
	}
	ll ans=0;
	for(int i=0;i<int(types.size());i++)
		ans=(ans+memo[n][i])%MOD;
	std::cout << ans << '\n';
}