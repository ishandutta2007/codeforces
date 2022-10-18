#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll ans=0;
	for(int i=1;i<=k;i++)
	{
		ans=ans+(n*m-(n-2)*(m-2));
		n-=4;
		m-=4;
	}
	cout<<ans<<endl;
	return 0;
}
//iuycrsifddwaeiurta