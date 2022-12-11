#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll r,b,k; 
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>r>>b>>k;
		ll g=__gcd(r,b);
		r/=g;b/=g;
		if(r>b)swap(r,b);
		ll ans=(b-2)/r+1;
		if(ans<k)puts("OBEY");
		else puts("REBEL");
	}
}