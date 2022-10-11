#include <cstdio>
#include <iostream>

const int ms=200200;

int freq[ms];

typedef long long ll;

const ll MOD=ll(1e9)+7;

ll fexp(ll x, ll e)
{
	ll ans=1;
	while(e)
	{
		if(e&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		e>>=1;
	}
	return ans;
}

ll comb(ll x)
{
	return ((x)*(x+1))/2;
}

ll left[ms], right[ms];

int main()
{
	int n;
	std::cin >> n;
	while(n--)
	{
		int temp;
		scanf("%i",&temp);
		freq[temp]++;
	}
	ll divs=1;
	left[0]=freq[0]+1;
	right[ms-1]=freq[ms-1]+1;
	for(int i=1;i<ms;i++)
	{
		left[i]=left[i-1]*(freq[i]+1)%(MOD-1);
		right[ms-1-i]=right[ms-i]*(freq[ms-1-i]+1)%(MOD-1);
	}
	ll ans=1;
	for(int i=0;i<ms;i++)
	{
		if(!freq[i])
			continue;
		ll cur_combs=comb(freq[i]);
		ll cur_divs=(left[i-1]*right[i+1])%(MOD-1);
		ll counting=fexp(i, cur_combs);
		counting=fexp(counting, cur_divs);
		ll cur_tot=counting%MOD;
		//std::cout << i << ": combs is " << cur_combs << ", divs is " << cur_divs << " tot is " << cur_tot << '\n';
		//std::cout << "counting is " << counting << '\n';
		ans=ans*cur_tot%MOD;
	}
	std::cout << ans << '\n';
}