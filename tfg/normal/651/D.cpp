#include <iostream>
#include <algorithm>

const int ms=5*100100;

typedef long long ll;

ll left[ms], right[ms];

int n;
ll a, b, t;

std::string str;

int cost[ms];

int main()
{
	std::cin >> n >> a >> b >> t >> str;
	for(int i=0;i<n;i++)
	{
		if(i)
			cost[i]=a;
		cost[i]++;
		if(str[i]=='w')
			cost[i]+=b;
	}
	left[0]=cost[0];
	right[n-1]=cost[n-1];
	for(int i=1;i<n;i++)
	{
		left[i]=left[i-1]+cost[i];
		right[n-i-1]=right[n-i]+cost[n-i-1];
	}
	if(left[n-1]<=t)
	{
		std::cout << n << '\n';
		return 0;
	}
	/*for(int i=0;i<n;i++)
		std::cout << left[i] << ' ';
	std::cout << '\n';
	for(int i=0;i<n;i++)
		std::cout << right[i] << ' ';
	std::cout << '\n';*/
	int ans=0;
	for(int i=0;left[i]<=t;i++)
	{
		ll cur_cost=left[i]+a*i;
		int l, r;
		l=i+1;
		r=n;
		while(l!=r)
		{
			int mid=(l+r)/2;
			ll nxt_cost=cur_cost+right[mid];
			if(nxt_cost<=t)
				r=mid;
			else
				l=mid+1;
		}
		int cur_ans=i+1+(n-r);
		//std::cout << "on " << i << " to " << l << ", cur ans is " << cur_ans << '\n';
		//std::cout << cur_cost+right[l] << '\n';
		ans=std::max(ans, cur_ans);
	}
	for(int i=n-1;right[i]+cost[0]<=t;i--)
	{
		ll cur_cost=right[i]+a*(n-i);
		int l, r;
		l=0;
		r=i-1;
		while(l!=r)
		{
			int mid=(l+r+1)/2;
			ll nxt_cost=cur_cost+left[mid];
			if(nxt_cost<=t)
				l=mid;
			else
				r=mid-1;
		}
		int cur_ans=n-i+1+l;
		//std::cout << "on " << i << " to " << l << ", cur ans is " << cur_ans << '\n';
		//std::cout << cur_cost+left[l] << '\n';
		ans=std::max(ans, cur_ans);
	}
	std::cout << ans << '\n';
}