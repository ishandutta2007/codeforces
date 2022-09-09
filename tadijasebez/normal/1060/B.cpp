#include <bits/stdc++.h>
using namespace std;
#define ll long long
int sum(ll x){ int ans=0;while(x>0) ans+=x%10,x/=10;return ans;}
int main()
{
	ll n,c=0,t,a=0;
	scanf("%lld",&n);t=n;
	while(t>0) c++,t/=10;
	while(--c) a=a*10+9;
	printf("%i\n",sum(a)+sum(n-a));
	return 0;
}