#include <iostream>

typedef long long int ll;

ll n, k;

ll solve(ll steps, ll ind)
{
	ll num=(1LL<<steps)-1;
	if(ind==(num+1)/2)
		return steps;
	else if(ind>(num+1)/2)
		ind-=(num+1)/2;
	return solve(steps-1,ind);
}

int main()
{
	std::cin >> n >> k;
	std::cout << solve(n,k) << '\n';

	/*int test=4;
	int limit=(1<<test)-1;
	for(int i=1;i<=limit;i++)
		std::cout << solve(test,i) << ' ';
	std::cout << '\n';*/
}