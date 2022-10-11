#include <iostream>
#include <map>

typedef long long ll;

std::map<ll, ll> memo;

ll get_size(ll n)
{
	if(n==0 || n==1)
		return 1;
	if(memo[n])
		return memo[n];
	else
		return memo[n]=2*get_size(n/2)+1;
}

ll solve(ll n, ll pos)
{
	if(n<=1)
		return n;
	ll under=get_size(n/2);
	//std::cout << "size under " << n << " is " << under << ", on pos " << pos << '\n';
	if(pos<=under)
		return solve(n/2, pos);
	else if(under+1==pos)
		return n%2;
	else
		return solve(n/2, pos-under-1);
}

int main()
{
	ll n, l, r;
	std::cin >> n >> l >> r;
	int ans=0;
	//for(int i=1;i<=r;i++)std::cout << solve(n, i) << ' ';std::cout << '\n';
	for(ll i=l;i<=r;i++)
	{
		ans+=solve(n, i);
	}
	std::cout << ans << '\n';
}