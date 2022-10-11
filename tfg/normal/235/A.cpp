#include <iostream>
#include <algorithm>

typedef long long int ll;

ll ans=0;
ll on;
ll g_ans=0;

ll gcd(ll a, ll b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
	return a*(b/gcd(a,b));
}

int main()
{
	ll n;
    std::cin >> n;
    if(n>300)
    {
	    for(ll i=n;i>n-1000 && i>0;i--)
	    {
	    	int got=0;
	    	ll cur_ans=i;
	    	for(ll j=n;j>i-1000 && j>0 && got<2;j--)
	    	{
	    		if(gcd(cur_ans, j)==1)
	    		{
	    			got++;
	    			cur_ans*=j;
	    		}
	    	}
	    	g_ans=std::max(g_ans, cur_ans);
	    }
	}
	else
	{
		for(ll i=n;i>0;i--)
		{
			for(ll j=i;j>0;j--)
			{
				ll lcm1=lcm(i, j);
				for(ll k=j;k>0;k--)
				{
					ll lcm2=lcm(lcm1,k);
					g_ans=std::max(g_ans,lcm2);
					if(gcd(lcm1, k)==1)
						break;
				}
			}
		}
	}
    std::cout << g_ans << '\n';
}