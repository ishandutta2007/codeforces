#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v[70];
int main()
{
	int n;
	ll x;
	scanf("%i",&n);
	int m=n;
	while(n--)
	{
		scanf("%lld",&x);
		int cnt=0;
		ll y=x;
		while(y%2==0) y/=2,cnt++;
		v[cnt].push_back(x);
	}
	int t=0;
	for(int i=1;i<70;i++) if(v[i].size()>v[t].size()) t=i;
	//int t=1;
	//if(v[0].size()<v[1].size()) t=0;
	printf("%i\n",m-v[t].size());
	for(int i=0;i<70;i++) if(i!=t)
	{
		for(ll y:v[i]) printf("%lld ",y);
	}
	return 0;
}