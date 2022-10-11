#include <string>
#include <iostream>

typedef long long int ll;

const ll MOD=ll(1e9)+7;

std::string str;

int n, k;

ll fat[101000], ifat[101000];

ll fexp(ll num, ll e)
{
	ll ans=1;
	while(e)
	{
		if(e&1)
		{
			ans=(ans*num)%MOD;
		}
		num=(num*num)%MOD;
		e=e>>1;
	}
	return ans;
}

ll combs(int a, int b)
{
	if(b>a) return 0;
	ll ans=(fat[a]*ifat[b])%MOD;
	//std::cout << "returning " << ans << std::endl;
	ans=(ans*ifat[a-b])%MOD;
	//std::cout << "returning " << ans << std::endl;
	return ans;
}

ll val(int a)
{
	return (ll)str[a]-'0';
}

int main()
{
	std::cin >> n >> k >> str;
	fat[0]=ifat[0]=1;
	for(int i=1;i<=n;i++)
	{
		fat[i]=(fat[i-1]*i)%MOD;
		ifat[i]=fexp(fat[i],MOD-2);
		//std::cout << "res: " << (fat[i]*ifat[i])%MOD << std::endl;
	}
	//ll ans=((val(n-1))*combs(n-1,k))%MOD;
	ll ans=0;
	//std::cout << "ans is " << ans << std::endl;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		sum=(sum+val(i))%MOD;
	}
	ll base=1;
	for(int i=n-1;i>=0;i--)
	{
		sum=(sum-val(i)+MOD)%MOD;
		int inter=n-i;
		//std::cout << "on " << i << " sum is " << sum << " base is " << base << std::endl;
		//std::cout << "has combs: " << combs(n-1-inter,k-1) << " inter is " << inter << std::endl;
		ans=(ans+((sum*combs(n-1-inter,k-1))%MOD)*base)%MOD;
		ans=(ans+((val(i)*base)%MOD)*combs(n-inter,k))%MOD;
		base=(base*10)%MOD;
		//std::cout << "ans is " << ans << std::endl;
	}
	std::cout << ans << std::endl;
}