#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[300005];
ll b[300005];
int main()
{
	ll n,m;
	cin>>n;
	ll ta=0,tb=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		ta+=a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%I64d",&b[i]);
		tb+=b[i];
	}
	if(ta!=tb)
	{
		cout<<"-1\n";
		return 0;
	}
	ta=1,tb=1;
	ll na=0,nb=0;
	int ans=0;
	for(int i=1;i<=n+m;i++)
	{
		if(na>nb)
		{
			nb+=b[tb++];
		}
		else
		{
			na+=a[ta++];
		}
		if(na==nb)
		{
			na=0;
			nb=0;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}