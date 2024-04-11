#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,m;
	cin>>n>>m;
	if(m==0)
	{
		cout<<n<<" "<<n;
		return 0;
	}
	cout<<(max(0LL,n-m*2))<<" ";
	m*=2;
	ll l=0,r=n;
	while(l<r)
	{
		ll mid=(l+r+1)/2;
		if((mid-1)*(mid)>=m)
		{
			r=mid-1;
		}
		else
		{
			l=mid;
		}
	}
	if(l*(l-1)<m)
	{
		l++;
	}
//	cout<<l<<endl;
	printf("%I64d ",n-l);
	return 0;
}