#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
const ll d[]={0,4,6,10,15,21,27,33,39,43,46,48,49};
int main()
{
	cin>>n;
	ll ans=0;
	if(n<=12)
	{
		for(int i=1;i<=n;++i)ans+=d[i];
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<=12;++i)ans+=d[i];
		ans+=1ll*(n-12)*49;
		cout<<ans<<endl;
	}
	return 0;
}