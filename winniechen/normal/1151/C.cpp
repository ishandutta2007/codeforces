#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
const int mod = 1000000007;
ll p[105],s[105],l1[105],l2[105],L,R;
ll calc(ll x)
{
	for(int i=60;~i;i--)
		if(p[i]<=x)
		{
			if(i&1)return (s[i]+((l2[i]+x-p[i]-1)%mod)*((x-p[i])%mod))%mod;
			return (s[i]+((l1[i]+x-p[i]-1)%mod)*((x-p[i])%mod))%mod;
		}
	return 0;
}
int main()
{
	ll lst1=1,lst2=2;l1[0]=1,l2[0]=2;
	for(int i=1;i<=60;i++)
	{
		p[i]=p[i-1]+(1ll<<(i-1));
		if(i&1)s[i]=(s[i-1]+((lst1+(1ll<<i-1)-1)%mod)*((1ll<<i-1)%mod))%mod,lst1+=1ll<<i;
		else s[i]=(s[i-1]+((lst2+(1ll<<i-1)-1)%mod)*((1ll<<i-1)%mod))%mod,lst2+=1ll<<i;
		l1[i]=lst1,l2[i]=lst2;
	}
	scanf("%lld%lld",&L,&R);
	printf("%lld\n",((calc(R)-calc(L-1))%mod+mod)%mod);
}
// 1,2,4,3,5,7,9,6,8,10,12,14,16,18,20,11,13,15,17