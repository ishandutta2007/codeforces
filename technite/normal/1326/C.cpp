#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,n,k,l=0,ans=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		if(a>n-k)
		{
			if(l) ans=ans*(i-l)%998244353;
			l=i;
		}
	}	
	cout<<(n+n+1-k)*k/2<<" "<<ans;
	return 0;
}