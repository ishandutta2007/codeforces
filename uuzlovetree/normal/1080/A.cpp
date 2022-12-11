#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
int main()
{
	cin>>n>>k;
	ll r=n*2,g=n*5,b=n*8;
	ll ans=0;
	if(r%k==0)ans+=r/k;else ans+=r/k+1;
	if(g%k==0)ans+=g/k;else ans+=g/k+1;
	if(b%k==0)ans+=b/k;else ans+=b/k+1;
	cout<<ans<<endl;
	return 0;
}