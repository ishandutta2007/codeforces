#include <iostream>
#include <string>

const int ms=1010;

typedef long long ll;

const ll MOD=ll(1e9)+7;

int n;
std::string str;
int a[ms];

int max_freq[26];

ll memo[ms];
bool visit[ms];
int hmm[ms];

int longest=0;

ll dp(int on)
{
	if(on>=n)
		return 1;
	ll &ans=memo[on];
	if(visit[on])
		return ans;
	visit[on]=true;
	ans=0;
	int to=on;
	int limit=max_freq[a[on]];
	while(to<n && to-on+1<=limit)
	{
		ans=(ans+dp(++to))%MOD;
		limit=std::min(limit, max_freq[a[to]]);
		
		
		//std::cout << "adding " << to << " to " << on << '\n';
		//std::cout << "ans is " << ans << '\n';
	}
	//std::cout << "from " << on << " to " << to << '\n';
	longest=std::max(longest, to-on);
	hmm[on]=to;
	return ans;
}

int main()
{
	std::cin >> n >> str;
	for(int i=0;i<n;i++)
	{
		a[i]=str[i]-'a';
	}
	for(int i=0;i<26;i++)
	{
		std::cin >> max_freq[i];
	}


	std::cout << dp(0) << '\n';
	std::cout << longest << '\n';
	int on=0;
	int count=0;
	while(on<n)
	{
		count++;
		on=hmm[on];
	}
	std::cout << count << '\n';
}