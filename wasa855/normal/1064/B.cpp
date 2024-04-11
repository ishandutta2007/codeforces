#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ll n;
		scanf("%I64d",&n);
		ll ans=0;
		while(n)
		{
			ans+=(n%2);
			n/=2;
		}
		cout<<(ll)pow(2,ans)<<endl;
	}
	return 0;
}