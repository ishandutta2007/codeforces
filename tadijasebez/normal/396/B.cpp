#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool Check(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
pair<int,int> Get(int n)
{
	pair<int,int> ans;
	for(ans.first=n;!Check(ans.first);ans.first--);
	for(ans.second=n+1;!Check(ans.second);ans.second++);
	return ans;
}
int main()
{
	int t,n,i;
	scanf("%i",&t);
	while(t--)
	{
		scanf("%i",&n);
		pair<int,int> p=Get(n);
		ll a=p.first-2,b=p.first*2;
		ll c=n-p.first+1,d=(ll)p.first*p.second;
		ll e=a*p.second+c*2,f=d*2;
		ll g=__gcd(e,f);
		e/=g;f/=g;
		printf("%lld/%lld\n",e,f);
	}
	return 0;
}