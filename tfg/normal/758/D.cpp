#include <iostream>
#include <string>
#include <algorithm>

typedef long long int ll;

const int ms=100;
const int INF=0x3f3f3f3f;

std::string num;

int n;
int size[ms];

void get_size(int x)
{
	if(num[x]=='0')
	{
		size[x]=1;
		return;
	}
	ll cur=0;
	int on=x;
	while(cur<n && on<num.size())
	{
		cur=10*cur+num[on]-'0';
		//std::cout << "including " << num[on] << ", cur = " << cur << '\n';
		on++;
	}
	if(on==num.size() && cur<n)
		on++;
	size[x]=on-x-1;
	//std::cout << "size on " << x << " is " << size[x] << '\n';
}

int memo[ms];
int to[ms];
bool visit[ms];

int dp(int on)
{
	if(on>=num.size())
		return 0;
	int &ans=memo[on];
	if(visit[on])
		return ans;
	visit[on]=true;
	ans=INF;
	for(int i=0;i<size[on];i++)
	{
		int cur_ans=dp(on+i+1)+1;
		if(cur_ans<ans)
		{
			ans=cur_ans;
			to[on]=on+i+1;
		}
	}
	return ans;
}

int main()
{
	std::cin >> n >> num;
	for(int i=0;i<num.size();i++)
		get_size(i);
	dp(0);
	int on=0;
	ll ans=0;
	while(on<num.size())
	{
		ll cur_ans=0;
		int cur=on;
		//std::cout << "on " << on << " going to " << to[on] << '\n';
		while(cur<to[on])
		{
			cur_ans=cur_ans*10+num[cur]-'0';
			cur++;
		}
		on=cur;
		ans=n*ans+cur_ans;
	}
	std::cout << ans << '\n';
}